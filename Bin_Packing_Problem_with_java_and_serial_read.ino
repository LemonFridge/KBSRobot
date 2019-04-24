// Include the Servo library 
#include <Servo.h> 

#define motorsnelheid1 4
#define motorrichting1 5
#define motorsnelheid2 6
#define motorrichting2 7

// Declare the Servo pin 
int servoPin1 = 13;
int servoPin2 = 12; 
// Create a servo object 
Servo Servo1; 
Servo Servo2;

int blok;
char blokKleur; // Als het nummer van de Java Applicatie voor servoKleur 1 is, is de kleur blauw. Als het 2 is, is de kleur rood.
byte Status;

int doosLinksBlauw = 10;
int doosRechtsBlauw = 10;

int doosLinksRood = 10;
int doosRechtsRood = 10;

int i;

void setup() {
   Servo1.attach(servoPin1);
   Servo2.attach(servoPin2);
   Serial.begin(9600);
   Serial.println("Setup klaar");
}

void loop() {

   if (Serial.available() > 0) {
    Status = Serial.read();

  }
  
  if (Status == 1) {
    if (i < 1) {
      analogWrite(motorsnelheid1, 210);
      digitalWrite(motorrichting1, HIGH);
      analogWrite(motorsnelheid2, 210);
      digitalWrite(motorrichting2, HIGH);
      i++;
}
   
   if(Status == 3){ //Kleur is blauw
    blokKleur = 1;
   }
   if(Status == 4){ //Kleur is rood
    blokKleur = 2;
   }

   if(Status == 5){ //Grootte van het blok 
    blok = Serial.read();
   }
    
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

  if(blokKleur == '1') { //Kleur is blauw
    
    Serial.println("De kleur van het blok is blauw!");
    
    if(doosLinksBlauw - blok >= 0) {

      Serial.println("Het blauwe blok gaat naar links!");
      Serial.println("8");
      doosLinksBlauw = doosLinksBlauw - blok;
      Servo1.write(0);  // Servo motor naar rechts, blok gaat naar linkerdoos.
      delay(1000);
      
    } else if (doosRechtsBlauw - blok >= 0) {

      Serial.println("Het blauwe blok gaat naar rechts!");
      Serial.println("9");
      doosRechtsBlauw = doosRechtsBlauw - blok;
      Servo1.write(45);  // Servo motor naar links, blok gaat naar rechterdoos.
      delay(1000);
      
    } else if (doosLinksBlauw - blok < 0 && doosRechtsBlauw - blok < 0) { // Dozen zijn beide vol.
      Serial.println("Dozen zijn vol!"); // Laat doos vol melding zien en stopt het programma.
      Serial.println("4");
      delay(10000);
    }
    
  } else if (blokKleur == '2') { // Kleur is rood
    Serial.println("De kleur van de blok is rood!");

    if(doosLinksRood - blok >= 0) {

      Serial.println("Het rode blok gaat naar links!");
      Serial.println("6");
      doosLinksRood = doosLinksRood - blok;
      Servo2.write(0);  // Servo motor naar rechts, blok gaat naar linkerdoos.
      delay(1000);
      
    } else if (doosRechtsRood - blok >= 0) {

      Serial.println("Het rode blok gaat naar rechts!");
      Serial.println("7");
      doosRechtsRood = doosRechtsRood - blok;
      Servo2.write(45);  // Servo motor naar links, blok gaat naar rechterdoos.
      delay(1000);
      
    } else if (doosLinksRood - blok < 0 && doosRechtsRood - blok < 0) { // Dozen zijn beide vol.
      Serial.println("Dozen zijn vol!"); // Laat doos vol melding zien en stopt het programma.
      Serial.println("5");
      delay(10000);
    }
  }
  }

if (Status == 2) {
    analogWrite(motorsnelheid1, 0);
    digitalWrite(motorrichting1, HIGH);
    analogWrite(motorsnelheid2, 0);
    digitalWrite(motorrichting2, HIGH);
    i = 0;
}

}
