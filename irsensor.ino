int IR_PIN = 4;
int G_PIN = 2;
int R_PIN = 15;
int B_PIN = 14;
int x;
void setup() {
  // put your setup code here, to run once:
  pinMode(IR_PIN, INPUT);
  pinMode(R_PIN,OUTPUT);
  pinMode(G_PIN,OUTPUT);
  pinMode(B_PIN,OUTPUT);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  x = digitalRead(IR_PIN);
  Serial.println(x);
  if(x == 1){
    analogWrite(G_PIN,255);
    analogWrite(R_PIN,255);
    analogWrite(B_PIN,255);
  }else{
    analogWrite(B_PIN,255);
    analogWrite(G_PIN,100);
    analogWrite(R_PIN,0);
  }
  delay(300);
}
