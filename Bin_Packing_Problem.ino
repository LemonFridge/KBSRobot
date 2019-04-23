// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin1 = 13;
int servoPin2 = 12; 
// Create a servo object 
Servo Servo1; 
Servo Servo2;

int blok = 3;
char blokKleur = '2'; // Als het nummer van de Java Applicatie voor servoKleur 1 is, is de kleur blauw. Als het 2 is, is de kleur rood.

int doosLinksBlauw = 10;
int doosRechtsBlauw = 10;

int doosLinksRood = 10;
int doosRechtsRood = 10;

void setup() {
   Servo1.attach(servoPin1);
   Servo2.attach(servoPin2);
   Serial.begin(9600);
   Serial.println("Setup klaar");
}

void testServos() {
   Servo1.write(0);  //links
   Servo2.write(0);  //links
   Serial.println("links");
   delay(3000);
   
   Servo1.write(90);  //rechts
   Servo2.write(90);  //rechts
   Serial.println("rechts");
   delay(3000);
}

void loop() {
  
   //testServos();
   
   if(blokKleur == '1') {
      Serial.print("Blok: ");
      Serial.println(blok);
      
      Serial.print("doosLinksBlauw: ");
      Serial.println(doosLinksBlauw);
      
      Serial.print("doosRechtsBlauw: ");
      Serial.println(doosRechtsBlauw);
      Serial.println();
      delay(3000);
    
   } else if (blokKleur == '2') {
      Serial.print("Blok: ");
      Serial.println(blok);
      
      Serial.print("doosLinks: ");
      Serial.println(doosLinksRood);
      
      Serial.print("doosRechts: ");
      Serial.println(doosRechtsRood);
      Serial.println();
      delay(3000);
   }

  if(blokKleur == '1') { // Kleur is blauw
    
    Serial.println("De kleur van de blok is blauw!");
    
    if(doosLinksBlauw - blok >= 0) {

      Serial.println("De blauwe blok gaat naar links!");
      Serial.println();
      doosLinksBlauw = doosLinksBlauw - blok;
      Servo1.write(0);  // Servo motor naar rechts, blok gaat naar linkerdoos.
      delay(1000);
      
    } else if (doosRechtsBlauw - blok >= 0) {

      Serial.println("De blauwe blok gaat naar rechts!");
      Serial.println();
      doosRechtsBlauw = doosRechtsBlauw - blok;
      Servo1.write(45);  // Servo motor naar links, blok gaat naar rechterdoos.
      delay(1000);
      
    } else if (doosLinksBlauw - blok < 0 && doosRechtsBlauw - blok < 0) { // Dozen zijn beide vol.
      Serial.println("Dozen zijn vol!"); // Laat doos vol melding zien en stopt het programma.
      Serial.println();
      delay(10000);
    }
    
  } else if (blokKleur == '2') { // Kleur is rood
    Serial.println("De kleur van de blok is rood!");

    if(doosLinksRood - blok >= 0) {

      Serial.println("De rode blok gaat naar links!");
      Serial.println();
      doosLinksRood = doosLinksRood - blok;
      Servo2.write(0);  // Servo motor naar rechts, blok gaat naar linkerdoos.
      delay(1000);
      
    } else if (doosRechtsRood - blok >= 0) {

      Serial.println("De blauw blok gaat naar rechts!");
      Serial.println();
      doosRechtsRood = doosRechtsRood - blok;
      Servo2.write(45);  // Servo motor naar links, blok gaat naar rechterdoos.
      delay(1000);
      
    } else if (doosLinksRood - blok < 0 && doosRechtsRood - blok < 0) { // Dozen zijn beide vol.
      Serial.println("Dozen zijn vol!"); // Laat doos vol melding zien en stopt het programma.
      Serial.println();
      delay(10000);
    }
  }
}
