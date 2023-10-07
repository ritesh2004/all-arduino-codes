#include <NewPing.h>

#define TRIGGER_PIN 18
#define ECHO_PIN 5
#define LED_PIN 2
#define BUZZER_PIN 18

NewPing sonar(TRIGGER_PIN, ECHO_PIN);
int ledState = LOW;
int buzzerState = LOW;

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  unsigned int distance = sonar.ping_cm();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance <= 0 || distance > 200) {
    // Out of range or invalid reading, ignore
    ledState = HIGH;
    return;
  }

  if (distance <= 10) {
    ledState = HIGH;
    buzzerState = HIGH;
    delay(50);
    ledState = LOW;
    buzzerState = LOW;
  } else if (distance <= 20) {
    ledState = HIGH;
    buzzerState = HIGH;
    delay(100);
    ledState = LOW;
    buzzerState = HIGH;
  } else if (distance <= 30) {
    ledState = HIGH;
    buzzerState = HIGH;
    delay(200);
    ledState = LOW;
    buzzerState = LOW;
  } else if (distance <= 40) {
    ledState = HIGH;
    buzzerState = HIGH;
    delay(400);
    ledState = LOW;
    buzzerState = LOW;
  } else if (distance <= 50) {
    ledState = HIGH;
    buzzerState = HIGH;
    delay(600);
    ledState = LOW;
    buzzerState = LOW;
  } else if (distance <= 60) {
    ledState = HIGH;
    buzzerState = HIGH;
    delay(800);
    ledState = LOW;
    buzzerState = LOW;
  } else {
    ledState = LOW;
    buzzerState = LOW;
    delay(10);
    ledState = LOW;
    buzzerState = LOW;
  }

  digitalWrite(LED_PIN, ledState);
  digitalWrite(BUZZER_PIN, buzzerState);
}
