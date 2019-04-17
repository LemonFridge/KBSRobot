// Include the Servo library 
#include <Servo.h> 
// Declare the Servo pin 
int servoPin1 = 13;
int servoPin2 = 12; 
// Create a servo object 
Servo Servo1; 
Servo Servo2;

int blok = 2;
int doosLinks = 10;
int doosRechts = 10;

void setup() {
   Servo1.attach(servoPin1); 
   Servo2.attach(servoPin2); 
}

void loop() {

 if(blok == doosLinks){ //past precies in links
  doosLinks = doosLinks - blok; //nieuwe max inhoud
  
  Servo1.write(0);  //rechts
 }
 else if(blok == doosRechts){ //past precies in rechts
  doosRechts = doosRechts - blok; //nieuwe max inhoud

  Servo1.write(45); //links
 }
 else if(doosLinks <= doosRechts && blok < doosLinks){ // links is kleiner dan rechts
  doosLinks = doosLinks - blok; //nieuwe max inhoud
  
  Servo1.write(0);  //rechts
 }
 else if(doosRechts < doosLinks && blok < doosRechts){ // rechts is kleiner dan links
  doosRechts = doosRechts - blok; //nieuwe max inhoud

  Servo1.write(45); //links
 }
else if(blok > doosLinks && blok < doosRechts){ // blok past niet in links
  doosRechts = doosRechts - blok; //nieuwe max inhoud

  Servo1.write(45); //links
}
else if(blok > doosRechts && blok < doosLinks){ // blok past niet in rechts
  doosLinks = doosLinks - blok; //nieuwe max inhoud
  
  Servo1.write(0);  //rechts
}else if(blok > doosLinks && blok > doosRechts){ // dozen zijn vol
  Serial.println(4);
}
}
