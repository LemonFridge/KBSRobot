// Include the Servo library
#include <Servo.h>

#define motorsnelheid1 4
#define motorrichting1 5
#define motorsnelheid2 6
#define motorrichting2 7

#define L1 A1
#define L2 A2
#define L3 A3

int lijn1_BreakPoint = 500;
int lijn2_BreakPoint = 500;
int lijn3_BreakPoint = 500;
int hoogte;

int value1 = 0;
int value2 = 0;
int value3 = 0;

// Declare the Servo pin
int servoPin1 = 13;
int servoPin2 = 12;
// Create a servo object
Servo Servo1;
Servo Servo2;

byte blok;
char blokKleur; // Als het nummer van de Java Applicatie voor servoKleur 1 is, is de kleur blauw. Als het 2 is, is de kleur rood.
byte Status;

byte doosLinksBlauw = 10;
byte doosRechtsBlauw = 10;

byte doosLinksRood = 10;
byte doosRechtsRood = 10;

boolean signaal = false;

void setup() {
  Servo1.attach(servoPin1);
  Servo2.attach(servoPin2);
  Serial.begin(9600);

  Servo1.write(65);
  Servo2.write(65);

  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
}

void loop() {


  if (analogRead(L3) < lijn3_BreakPoint) { // Checks if all linesensors are triggered.
    blok = 3
    Serial.println("3");
    delay(400);
  }
  else if (analogRead(L2) < lijn2_BreakPoint) { // Checks if linesensors 1 and 2 are triggered.
    blok = 2;
    Serial.println("2");
    delay(400);
  }
  else if (analogRead(L1) > lijn1_BreakPoint) {  // Checks if only linesensor 1 is triggered.
    blok = 1;
    Serial.println("1");
    delay(400);
  }

}

if (Serial.available() > 0) {

  Status = Serial.read();

  if (signaal) {
    byte maximaal = Serial.read();
    doosLinksBlauw = maximaal;
    doosRechtsBlauw = maximaal;
    doosLinksRood = maximaal;
    doosRechtsRood = maximaal;
    signaal = false;
  }

  if (Status == 1) {
    analogWrite(motorsnelheid1, 210);
    digitalWrite(motorrichting1, HIGH);
    analogWrite(motorsnelheid2, 210);
    digitalWrite(motorrichting2, HIGH);
  }


  if (Status == 2) {
    analogWrite(motorsnelheid1, 0);
    digitalWrite(motorrichting1, LOW);
    analogWrite(motorsnelheid2, 0);
    digitalWrite(motorrichting2, LOW);
  }

  if (Status == 3) { //Kleur is blauw
    blokKleur = 1;
  }
  if (Status == 4) { //Kleur is rood
    blokKleur = 2;
  }

  if (Status == 5) { //Grootte van het blok
    //signaal = true;
  }

  if (blokKleur == '1') { //Kleur is blauw

    if (doosLinksBlauw - blok >= 0) {

      doosLinksBlauw = doosLinksBlauw - blok;
      Servo1.write(0);  // Servo motor naar rechts, blok gaat naar linkerdoos.

      Serial.println("9");
    } else if (doosRechtsBlauw - blok >= 0) {

      doosRechtsBlauw = doosRechtsBlauw - blok;
      Servo1.write(45);  // Servo motor naar links, blok gaat naar rechterdoos.

      Serial.println("8");

    } else if (doosLinksBlauw - blok < 0 && doosRechtsBlauw - blok < 0) { // Dozen zijn beide vol.

      Serial.println("4");
    }

  } else if (blokKleur == '2') { // Kleur is rood

    if (doosLinksRood - blok >= 0) {

      doosLinksRood = doosLinksRood - blok;
      Servo2.write(45);  // Servo motor naar rechts, blok gaat naar linkerdoos.

      Serial.println("6");

    } else if (doosRechtsRood - blok >= 0) {

      doosRechtsRood = doosRechtsRood - blok;
      Servo2.write(0);  // Servo motor naar links, blok gaat naar rechterdoos.

      Serial.println("7");

    } else if (doosLinksRood - blok < 0 && doosRechtsRood - blok < 0) { // Dozen zijn beide vol.
      Serial.println("5");
    }
  }
}
}
