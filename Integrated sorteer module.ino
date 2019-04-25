#include <Servo.h>

#define S0 9
#define S1 10
#define S2 11
#define S3 12
#define sensorOut 8
#define L1 A0
#define L2 A1
#define L3 A2
#define motorsnelheid 6
#define motorrichting 7

int speaker = 2;
int lijn1_BreakPoint = 900;
int lijn2_BreakPoint = 900;
int lijn3_BreakPoint = 900;
int hoogte;
int redfrequency = 0;
int bluefrequency = 0;
byte Status;
int i;

Servo servo;
void setup() {

  servo.attach(A0);
  pinMode(motorsnelheid, OUTPUT);
  pinMode(motorrichting, OUTPUT);
  pinMode(S0, OUTPUT);

  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  pinMode(L3, OUTPUT);

  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  Serial.begin(9600);



}


void loop() {
  if (Serial.available() > 0) {
    Status = Serial.read();

  }
  
  if (Status == 1) {
    if (i < 1) {
      analogWrite(motorsnelheid, 210);
      digitalWrite(motorrichting, HIGH);
      i++;
    }

    
    // Setting red filtered photodiodes to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    // Reading the output frequency
    redfrequency = pulseIn(sensorOut, LOW);
    //Serial.print("R ");
    //Serial.print(redfrequency);
    // Printing the value on the serial monitor
    delay(10);


    // Setting Blue filtered photodiodes to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    // Reading the output frequency
    bluefrequency = pulseIn(sensorOut, LOW);
    //Serial.println(" B ");
    // Serial.print(bluefrequency);
    // Printing the value on the serial monitor

    delay(10);

    if ((redfrequency > 0) && (redfrequency < 2000)) {
      Serial.println("1");
      tone(speaker, 1000, 500);
      servo.write(50);
      delay(1000);
    }

    if ((bluefrequency < 2800 ) && (redfrequency > 1500)) {
      Serial.println("2");
      tone(speaker, 1000, 500);
      servo.write(120);
      delay(1000);
    }

  }
  if (Status == 2) {
    analogWrite(motorsnelheid, 0);
    digitalWrite(motorrichting, HIGH);
    i = 0;
  }
}
