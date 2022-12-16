# Gebruiksaanwijzing

### opladen / vervangen batterijen
In dit project wordt gebruik gemaakt van batterijen met een externe oplader.

Batterijen uit de linefollower halen:
Controleer of de linefollower uit staat. Haal vervolgens de batterijhouder uit het daarvoor voorziene slot van de linefollower. Verwijder hierna de batterijen uit de batterijhouder. Wees hierbij voorzichtig dat je niet aan de kabels trekt. 

<img width="242" alt="image" src="https://user-images.githubusercontent.com/87031331/208083550-f2c2ccbc-eff5-4173-b629-4302de6415d9.png">

Batterijen opladen:
Plaats beide batterijen juist in de batterijoplader en verbind deze via de usb-kabel met de nodige dongle aan een stekker. !Gebruik niet de usb-poort van een computer, deze kan de nodige stroomsterktes niet leveren.



<img width="152" alt="image" src="https://user-images.githubusercontent.com/87031331/208112702-9d41bb68-8c26-4081-9aab-590e6c66c8d0.png">


Verwijder na het opladen de batterijen van de oplader. !Lees aandachtig de handleiding van de oplader voor gebruik!
Plaatsen van de batterijen:
Eens de batterijen verwijdert zijn uit de oplader kunnen deze teruggeplaatst worden in de batterijhouder. Plaats de batterijen terug in de batterijhouder, rekeninghoudend met de polariteit van de batterijen. De plus op de batterij moet overeenkomen met de plus op de batterijhouder. Plaats de batterijhouder terug in het daarvoor voorziene slot op de linefollower.


<img width="222" alt="image" src="https://user-images.githubusercontent.com/87031331/208083802-a461a73e-406b-4880-b571-7e299f0bc337.png">


### draadloze communicatie
#### verbinding maken
Om met de smartphone te kunnen verbinden met de linefollower maken we gebruik van de app "Bluetooth terminal HC-05", die we kunnen downloaden in de PlayStore. 

<img width="138" alt="image" src="https://user-images.githubusercontent.com/87031331/208103003-7095e475-383c-44f1-a4af-c6791eb99d94.png">

Vervolgens zetten we de linefollower aan en zien we de rode en blauwe led op de HC-05 flikkeren met een frequentie van 4 blinks per seconde. 
Op het home-scherm van de app drukken we rechtsboven op 'SCAN' en kiezen we de HC-05. 

<img width="142" alt="image" src="https://user-images.githubusercontent.com/87031331/208103743-27fdc1b1-22ad-48ac-b33d-7141e115f5db.png">

Nu maakt de app verbinding met de HC-05 en krijgen we volgend scherm:

<img width="142" alt="image" src="https://user-images.githubusercontent.com/87031331/208104230-c5057fbd-21c1-4d5d-9ff4-37fa47d3130a.png">


De knipperfrequentie van de leds op de HC-05 is nu 2 blinks in 4 seconden.

opmerking: de knoppen onderaan het scherm staan bij mij al geconfigureerd, maar dat is uiteraard niet standaard. Om de knoppen te configureren druk je lang op knop tot volgend scherm verschijnt en configureer als volgt:

<img width="144" alt="image" src="https://user-images.githubusercontent.com/87031331/208104720-212a001a-671e-4dc4-b933-760c2bcaf5f6.png">

Als dit gebeurt is, kunnen we beginnen met het instellen van de parameters van de linefollower. Meer daarover hieronder. 




#### commando's
debug:

Wanneer we in de terminal onderaan het scherm 'debug' ingeven krijgen we de instelling van alle parameters te zien. (Of druk op de sneltoets 'debug', indien je die al geconfigureerd hebt).

<img width="144" alt="image" src="https://user-images.githubusercontent.com/87031331/208105762-7ad64763-7bd0-440b-9027-277ec6097a04.png">

Hieronder worden de parameters één voor één besproken; als ook de instelling ervan.

set start:

Om de linefollower te starten gebruiken we het commando 'set start'. Dit kunnen we in de terminal ingeven, maar makkelijker is om een sneltoets te configureren als volgt:

<img width="146" alt="image" src="https://user-images.githubusercontent.com/87031331/208106724-f06b123a-d0a5-4007-b811-808f7b8f6cac.png">

Na het ingeven van dit commando begint de linefollower te rijden en komt de parameter 'run' op 1 te staan.

set stop:

Om de linefollower te stoppen gebruiken we het commando 'set stop'. Dit kunnen we in de terminal ingeven, maar makkelijker is om een sneltoets te configureren als volgt:

<img width="141" alt="image" src="https://user-images.githubusercontent.com/87031331/208107047-a6a053e1-2455-4c0f-9e28-d1dcc030385f.png">

Na het ingeven van dit commando stopt de linefollower. 

set cycle [µs]  

Dit commando bepaald de 'cycletime' van de microcontroller en geeft aan hoe veel tijd er zit tussen het uitvoeren van twee loops. De precieze werking hiervan laten we hier achterwege, we moeten er enkel op letten dat dit getal ongeveer tweemaal zo groot is als de 'calculation time'. Een geldig commando zou bijvoorbeeld zijn: 'set cycle 3000'.

<img width="141" alt="image" src="https://user-images.githubusercontent.com/87031331/208108104-a71f538c-3e90-40ce-b3e9-c891cc18e26e.png">

set power [0..255]  

Dit commando bepaalt de kracht die de motoren krijgen. Uit tests blijkt dat een waarde van rond de 70 ideaal is. Een te hoge waarde zorgt ervoor dat de linefollower uit de bocht vliegt, terwijl een te lage waarde ervoor zorgt dat hij zeer schokkerig door de bochten komt. 
set diff [0..1]  

De diff-parameter bepaald de snelheid van de linefollower in bochten. Een ideale waarde hiervoor is 0.5.
set kp [0..]  

De 'kp' bepaalt hoe snel de linefollower reageert op een verandering van de lijn. Een ideale waarde hiervoor is 10.

set ki [0..]  

De 'ki' laten we in dit project gewoon op nul staan.

set kd [0..]  

De 'kd staat ons toe om het schokken van de linefollower weg te werken. Een ideale waarde hiervoor is 0.5.
(Opmerking: wanneer we op debug klikken krijgen we niet de ingegeven waarde te zien voor 'kd', maar een breuk hiervan.)

calibrate black  

Vooraleer we kunnen rijden moeten we eerst de sensor kalibreren. Eerst zetten we de sensor op een zwart vlak. Wanneer we nu het commando 'calibrate black' ingeven, kalibreert hij de sensor voor zwart. In de app ziet dit er als volgt uit:

<img width="143" alt="image" src="https://user-images.githubusercontent.com/87031331/208111829-cae79baf-e19c-4ce3-a4ca-fe33eabc09da.png">


calibrate white  

Vervolgens doen we hetzelfde voor wit met het commando 'calibrate white':

<img width="140" alt="image" src="https://user-images.githubusercontent.com/87031331/208111999-fa466f23-70de-4ce9-abfd-eb584724e993.png">


### kalibratie

Zie commando's Calibrate Black en calibrate white.


### settings
De robot rijdt stabiel met volgende parameters:  

<img width="134" alt="image" src="https://user-images.githubusercontent.com/87031331/208112452-a9cbe809-44ee-4056-b69c-c64e12ad536b.png">

(Opmerking: over de parameter 'knipperperiode' moeten we ons geen zorgen maken, deze parameter bepaalt enkel de frequentie waarmee de ingebouwde led op de arduino zal knipperen. Dit dient enkel ter controle.)


### start/stop button
Zie commando's 'set start' en 'set stop'.
