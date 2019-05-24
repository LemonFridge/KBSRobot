 #include <Servo.h>

#define S0 9
#define S1 10
#define S2 11
#define S3 12
#define sensorOut 8
#define motorsnelheid 6
#define motorrichting 7

int speaker = 2;

int redfrequency = 0;
int bluefrequency = 0;

byte Status = 2;
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


  // Setting frequency-scaling to 20%
  digitalWrite(S0, HIGH);
  digitalWrite(S1, LOW);
  servo.write(50);
  Serial.begin(9600);
}
void loop() {

  if (Serial.available() > 0) {
  Status = Serial.read();
  }

  if (Status == 0) {
      analogWrite(motorsnelheid, 215);
      digitalWrite(motorrichting, LOW);
      delay(4000);
      Status = 2;
      }
    
  // Status = 1;
  if (Status == 1) {
    if (i < 1) {
      analogWrite(motorsnelheid, 215);
      digitalWrite(motorrichting, HIGH);
      i++;
    }

    // Setting red filtered photodiodes to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, LOW);
    // Reading the output frequency
    redfrequency = pulseIn(sensorOut, LOW);
    delay(10);

    // Setting Blue filtered photodiodes to be read
    digitalWrite(S2, LOW);
    digitalWrite(S3, HIGH);
    // Reading the output frequency
    bluefrequency = pulseIn(sensorOut, LOW);
    delay(10);

   
    if ((redfrequency > 0) && (redfrequency < 1900)) {
      Serial.println("1");
      
      tone(speaker, 1000, 500);
      servo.write(50);
      delay(1000);
    }
    
    if ((bluefrequency < 2800 ) && (redfrequency > 2400)) {
      Serial.println("2");
      tone(speaker, 1000, 500);
      servo.write(115);
      delay(1000);
    }

  }

  
  if (Status == 2) {
    analogWrite(motorsnelheid, 0);
    digitalWrite(motorrichting, HIGH);
    i = 0;
  }
}
