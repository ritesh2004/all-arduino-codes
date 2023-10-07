#define buttonPin 4
#define led 5

void setup() {
  Serial.begin(115200);
  pinMode(buttonPin, INPUT);
  pinMode(led,OUTPUT);
}

void loop() {
  int x = digitalRead(buttonPin);
  Serial.println(x);
  if (x == 1){
    digitalWrite(led,1);
  }
  else{
    digitalWrite(led,0);
  }
  delay(50);
}
