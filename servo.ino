#include<ESP32Servo.h>

int PIN = 5;
Servo myServo;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  myServo.attach(PIN);
  myServo.write(0);
}

void loop() {
  // put your main code here, to run repeatedly:
//  for (int i=0;i<180;i++){
//    myServo.write(i);
//    delay(100);
//  }
//  delay(1000);
//  for (int i=180;i>=0;i--){
//    myServo.write(i);
//    delay(100);
//  }
//  delay(1000);
}
