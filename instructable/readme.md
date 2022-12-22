# Instructable

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

### stap 1: Benodigdheden
Bestel alle componenten uit de bill of materials. In dit project werken we met een breadboard, wat het solderen top een minimum beperkt en ervoort zorgt dat fouten gemakkelijk opgelost kunnen worden. Een nadeel hieraan is echter dat slechte connecties vaker kunnen voorkomen. 

<img width="197" alt="image" src="https://user-images.githubusercontent.com/87031331/209173349-42d59d3f-5307-4f85-81b4-87fde05bcfaf.png">



### Stap 2: Solderen
Er dienen maar vier dingen gesoldeerd te worden, de wielen, de batterijhouder, de h-brug en de sensoren.
De wielen:
Het solderen van de wielen is simpel, we moeten enkel een rood draadje aan de + solderen en een zwart aan de -. 
Je kan een mannelijke dupon gemakkelijk verbinden aan klem van het motortje, waarna je de hechting kan solderen. Let hierbij wel op dat je met de soldeerbout enkel aan de klem van het motortje komt en niet aan het zwarte plastieken omhulsel, dit zou immers tot schade kunnen leiden.

<img width="257" alt="image" src="https://user-images.githubusercontent.com/87031331/209175065-a7b3b76b-49f6-4ba4-9400-91574d96fc47.png">


Wat de batterijhouder betreft moeten we de rode draad in twee knippen en er een schakelaar tussen solderen. De schakelaar die wij hebben heeft 3 aansluitingen, waarvan we de middelste en één van de buitenste gebruiken. De middelste aansluiting is voor de verbinding stroomopwaarts (dus naar de batterijhouder), die aan de zijkant is voor de pin. Hiervoor zal je eerst de rode draad in twee moeten knippen en dan beide uiteinden strippen. 
Vervolgens kunnen we solderen. Naderhand kunnen we met secondelijm het schakelaartje aan de zijkant van de batterijhouder plakken 

<img width="246" alt="image" src="https://user-images.githubusercontent.com/87031331/209175447-40d1163a-c8dd-4ce4-be47-a0320e8a5b02.png">


Ook heb ik aan het uiteinde van de zwarte en rode kabel een mannelijke gesoldeerd (dergelijke pinnen komen samen met de sensor, daar kan je er twee van gebruiken, we hebben die immers niet allemaal nodig). Dit vergemakelijkt het gebruik en geef wat meer zekerheid op een goede connectie later.

<img width="246" alt="image" src="https://user-images.githubusercontent.com/87031331/209175492-1186f48a-cb00-47da-9d43-283f97c2b3f8.png">

Op de H-brug moeten we de twee rijen pinnen solderen, één langs elke kant. Dit is simpel, vergewis je er gewoon van dat je geen kortsluiting creëert tussen de pinnen.

<img width="255" alt="image" src="https://user-images.githubusercontent.com/87031331/209176003-3387ac30-7561-4eb0-bdd2-5db70c3aad16.png">

Voor de sensoren geldt grotendeels hetzelfde als voor de H-brug, we moeten enkel opletten dat we de lange pinnen aan de juiste kant van de sensoren hebben zitten. De sensoren zitten immers aan de onderkant terwijl de bekabeling aan de bovenkant moet komen te zitten. Soldeer dus aan de kant van de sensoren, zodat de lange pinnen aan de andere kant zitten. 

<img width="150" alt="image" src="https://user-images.githubusercontent.com/87031331/209176864-0f681640-8418-4d4d-b19f-9d92b1eb11a8.png">

<img width="146" alt="image" src="https://user-images.githubusercontent.com/87031331/209176925-0e9cf5d3-6394-4174-b46c-a5e7ad1d8215.png">


### Stap 3: Assembleren
Nu we al onze componenten geprepareerd hebben kunnen we beginnen met assembleren. Hierbij beginnen we met de arduino, die we met M3-bouten kunnen vastzetten zoals op onderstaande foto: 

<img width="253" alt="image" src="https://user-images.githubusercontent.com/87031331/209177295-59dab77c-905f-4dbf-a8c2-82f2122ddb47.png">

Vervolgens plakken we he breadboard ernaast:

<img width="235" alt="image" src="https://user-images.githubusercontent.com/87031331/209177521-df03d60f-b27d-49e4-9a17-0e9d681cdcf0.png">
 
De sensor volgt. Deze zetten we vast met M2-bouten (of met stompe nagels en secondelijm indien je geen M2's kan vinden).

Daarna plaatsen we de motoren met wielen in de voorziene slots.

<img width="236" alt="image" src="https://user-images.githubusercontent.com/87031331/209178068-30181e06-d53e-4113-9d49-6b91b33fe066.png">

Nu kunnen we de H-brug en de HC-05 op het breadboard plaatsen.

<img width="257" alt="image" src="https://user-images.githubusercontent.com/87031331/209178259-3f5e89aa-aec8-4acd-a0ab-1533d74dfbd3.png">
 
 En de batterijhouder in de slot plaatsen:
 
 <img width="233" alt="image" src="https://user-images.githubusercontent.com/87031331/209178372-fcf077f9-fbc2-438a-ba32-629ac4bed23b.png">
 
 Vervolgens bouwen we met dupondraadjes de schakeling na zoals op het elektrisch schema. 
 
 ### Stap 4: Compileren
 
 Alq laatste compileren we de microcontroller. Download eerst de code en zet deze in een instantie van de Arduino IDE environment. Verbinde vervolgens de arduino met de pc en laad de code op. Als dit goed verlopen is kunnen we de Arduino weer loskoppelen. Nu zijn we klaar voor gebruik.
 
 <img width="507" alt="image" src="https://user-images.githubusercontent.com/87031331/209178956-a07fa3eb-6cfb-446e-8925-2b4ffb5a38fc.png">






