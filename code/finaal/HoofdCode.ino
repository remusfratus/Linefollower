#include "SerialCommand.h"
#include "EEPROMAnything.h"

#define SerialPort Serial1
#define Baudrate 9600



#define  BIN2 10 // MotorRightForward (Benable)
#define  BIN1 11 // MotorRightBackward (Bphase)
#define  AIN2 3 // MotorLeftForward(Aenable)
#define  AIN1 9 // MotorLeftForward (Aphase)


SerialCommand sCmd(SerialPort); // SerialCommand object declaration

bool run = false;
unsigned long previous;
unsigned long calculationTime; 
unsigned long Difference; 

float iTerm = 0;
float lastErr; 

const int sensor[] = {A0, A1, A2, A3, A4, A5};

 float debugPosition;
struct param_t
{
  unsigned long cycleTime;
  unsigned long knipperPeriode;
  /* andere parameters die in het eeprom geheugen moeten opgeslagen worden voeg je hier toe ... */
  int black[6];
  int white[6];
  int power; 
  float diff;
  float kp;  
  float ki; 
  float kd;
  
} params;
bool ledstate = false;
unsigned long lastToggle;
int interruptPin = 7;
int normalised[6];
   float output;
void setup()
{
  SerialPort.begin(Baudrate);
  

  sCmd.addCommand("set", onSet);
  sCmd.addCommand("debug", onDebug);
  sCmd.addCommand("calibrate", onCalibrate);

  sCmd.setDefaultHandler(onUnknownCommand);

  EEPROM_readAnything(0, params);

  
  pinMode(interruptPin, INPUT); 
  attachInterrupt(digitalPinToInterrupt(interruptPin), stop, RISING);
  
  pinMode(BIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(AIN1, OUTPUT);

  pinMode(13, OUTPUT);

  digitalWrite (13, HIGH);
  delay (500);
  digitalWrite (13, LOW);
  delay (100);
  digitalWrite (13, HIGH);
  delay (100);
  digitalWrite (13, LOW);
  delay (100);
  digitalWrite (13, HIGH);
  delay (500);
  digitalWrite (13, LOW);
  SerialPort.println("ready");
}

void loop()
{
  
  sCmd.readSerial(); // listen and process serial commands

 

  unsigned long current = micros();
  if (current - previous >= params.cycleTime)
  {
    previous = current;
     /* code die cyclisch moet uitgevoerd worden programmeer je hier ... */

     

     /* normaliseren en interpoleren sensor */
     for (int i = 0; i < 6; i++)
     {
        normalised[i] = map(analogRead(sensor[i]), params.black[i], params.white[i], 0, 1000);
        
        
     }


     //Interpolate

    float position;
    int index = 0;

     for (int i = 1; i < 6; i++) if (normalised[i] < normalised[index]) index = i;

     //if (normalised[index] > 700) run =false;
     
     
     if (index == 0)position = -30;
     else if (index == 5)position = 30;
     else
     {
      
     int sNul = normalised[index];
     int sMinEen = normalised [index-1];
     int sPlusEen = normalised[index+1];

     float b = sPlusEen - sMinEen;
     b = b / 2;

     float a = sPlusEen - b - sNul;

     position = -b / (2 * a);
     position += index;
     position -= 2.5;

     position *= 15;

     

     }

     debugPosition = position;

     /* pid regeling */
     
     float error = -position;
     output = error * params.kp;



     iTerm += params.ki*error;
     iTerm = constrain(iTerm, -510, 510);
     output += iTerm;


     output += params.kd * (error - lastErr);
     lastErr = error;

    

    /* aansturen motoren */   

     output = constrain(output, -510, 510);

     int powerLeft = 0;
     int powerRight = 0;

     if (run) if (output >= 0)
     {
      powerLeft = constrain(params.power + params.diff * output, -255, 255);
      powerRight = constrain(powerLeft - output, -255, 255);
      powerLeft = powerRight + output;
     }
     else
     {
      powerRight = constrain(params.power - params.diff * output, -255, 255);
      powerLeft = constrain(powerRight + output, -255, 255);
      powerRight = powerLeft - output;
     }

     
    analogWrite(AIN1, powerLeft > 0 ? powerLeft : 0);
    analogWrite(AIN2, powerLeft < 0 ? -powerLeft : 0);
    analogWrite(BIN2, powerRight > 0 ? powerRight : 0);
    analogWrite(BIN1, powerRight < 0 ? -powerRight : 0);
    
  }


  //Knipperlichtje
  if (current - lastToggle >= params.knipperPeriode){

    lastToggle = current;
    ledstate = !ledstate;

   digitalWrite(13, ledstate);
    
  }

  unsigned long difference = micros() - current;
  if (difference > calculationTime) calculationTime = difference;
  
}
    



void onSet()
{

 
  char* param = sCmd.next();
  char* value = sCmd.next();

   
  if (strcmp(param, "start") == 0) run = true;
  else if (strcmp(param, "stop") == 0) run = false;
  
  else if (strcmp(param, "knipper")== 0) params.knipperPeriode = atol(value);
  
  else if (strcmp(param, "power") == 0) params.power = atol(value); 
  else if (strcmp(param, "diff") == 0) params.diff = atof(value);
  else if (strcmp(param, "kp") == 0) params.kp = atof(value);
 

    if (strcmp(param, "cycle") == 0)
  {
    long newCycleTime = atol(value);
    float ratio = ((float) newCycleTime) / ((float) params.cycleTime);

    params.ki *= ratio;
    params.kd /= ratio;

    params.cycleTime = newCycleTime;
  }
  else if (strcmp(param, "ki") == 0)
  {
    float cycleTimeInSec = ((float) params.cycleTime) / 1000000;
    params.ki = atof(value) * cycleTimeInSec;
  }
  else if (strcmp(param, "kd") == 0)
  {
    float cycleTimeInSec = ((float) params.cycleTime) / 1000000;
    params.kd = atof(value) / cycleTimeInSec;
  }
  
 
  EEPROM_writeAnything(0, params);
}

void onDebug()
{

  SerialPort.print("run: ");
  SerialPort.println(run);
  
  SerialPort.print("cycle time: ");
  SerialPort.println(params.cycleTime);

  SerialPort.print("knipperperiode: ");
  SerialPort.println(params.knipperPeriode);

  
  SerialPort.print("calibratie zwart: ");
  for (int i = 0; i < 6; i++)
  {
    SerialPort.print(params.black [i]);
    SerialPort.print(" ");
  }SerialPort.println();

  SerialPort.print("calibratie wit: ");
  for (int i = 0; i < 6; i++)
  {
    SerialPort.print(params.white [i]);
    SerialPort.print(" ");
  }SerialPort.println();

  SerialPort.print("normalised: ");
  for (int i = 0; i < 6; i++)
  {
    SerialPort.print(normalised[i]);
    SerialPort.print(" ");
  }SerialPort.println();

  SerialPort.print("position: ");
  SerialPort.println(debugPosition);


  SerialPort.print("power: ");
  SerialPort.println(params.power);

  SerialPort.print("diff: ");
  SerialPort.println(params.diff);

  SerialPort.print("kp: ");
  SerialPort.println(params.kp);


  float cycleTimeInSec = ((float) params.cycleTime) / 1000000;
  float ki = params.ki / cycleTimeInSec;
  SerialPort.print("ki: ");
  SerialPort.println(params.ki);


  float kd = params.kd * cycleTimeInSec;
  SerialPort.print("kd: ");
  SerialPort.println(params.kd);

  
  
  /* parameters weergeven met behulp van het debug commando doe je hier ... */
  
  SerialPort.print("calculation time: ");
  SerialPort.println(calculationTime);
  calculationTime = 0;
}

void onCalibrate()
{
  char* param = sCmd.next();

  if (strcmp(param, "black") == 0)
  {
    SerialPort.print("start calibrating black... ");
    for (int i = 0; i < 6; i++) params.black[i]=analogRead(sensor[i]);
    SerialPort.println("done");
  }
  else if (strcmp(param, "white") == 0)
  {
    SerialPort.print("start calibrating white... ");    
    for (int i = 0; i < 6; i++) params.white[i]=analogRead(sensor[i]);  
    SerialPort.println("done");      
  }

  EEPROM_writeAnything(0, params);
}

void onUnknownCommand(char* command)
{
  SerialPort.print("unknown command: \"");
  SerialPort.print(command);
  SerialPort.println("\"");
}

void stop() {
  run = false;
}
