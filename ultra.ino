#include<NewPing.h>

int TRG = 4;
int ECHO = 5;
int LED = 2;
int BUZ = 18;

NewPing sonar(TRG,ECHO);

int distance;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
  pinMode(BUZ, OUTPUT);
}

void loop() {
//  digitalWrite(TRG, LOW);
//  delayMicroseconds(2);
//  digitalWrite(TRG, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(TRG, LOW);

  distance = sonar.ping_cm();
//  distance = (duration * 0.0343) / 2;
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");
  if (distance>50 && distance <= 60){
    digitalWrite(LED,HIGH);
    digitalWrite(BUZ,HIGH);
    delay(800);
    digitalWrite(LED,LOW);
    digitalWrite(BUZ,LOW);
    delay(800);
  }
  else if (distance>40 && distance <= 50){
    digitalWrite(LED,HIGH);
    digitalWrite(BUZ,HIGH);
    delay(600);
    digitalWrite(LED,LOW);
    digitalWrite(BUZ,LOW);
    delay(600);
  }
  else if (distance>30 && distance <= 40){
    digitalWrite(LED,HIGH);
    digitalWrite(BUZ,HIGH);
    delay(400);
    digitalWrite(LED,LOW);
    digitalWrite(BUZ,LOW);
    delay(400);
  }
  else if (distance>20 && distance <= 30){
    digitalWrite(LED,HIGH);
    digitalWrite(BUZ,HIGH);
    delay(200);
    digitalWrite(LED,LOW);
    digitalWrite(BUZ,LOW);
    delay(200);
  }
  else if (distance>10 && distance <= 20){
    digitalWrite(LED,HIGH);
    digitalWrite(BUZ,HIGH);
    delay(100);
    digitalWrite(LED,LOW);
    digitalWrite(BUZ,LOW);
    delay(100);
  }
  else if (distance>0 && distance <= 10){
    digitalWrite(LED,HIGH);
    digitalWrite(BUZ,HIGH);
    delay(50);
    digitalWrite(LED,LOW);
    digitalWrite(BUZ,LOW);
    delay(50);
  }
  else{
    digitalWrite(LED,HIGH);
    delay(10); 
  }
}
