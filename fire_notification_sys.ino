#include<WiFi.h>
#include<HTTPClient.h>
#include<ArduinoJson.h>

#define IR 4
#define LED 5
#define BUZZ 19

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(IR,INPUT);
  pinMode(LED,OUTPUT);
  pinMode(BUZZ,OUTPUT);
  WiFi.begin("Redmi9Power","ritesh713146");
  Serial.print("Connecting to Redmi9Power...");
  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("WiFi connected");
  Serial.println("Local IP Address");
  Serial.print(WiFi.localIP());
}

void send_email(){
  if (WiFi.status() == WL_CONNECTED){
    HTTPClient http;
    StaticJsonDocument<200> jsonDocument; // Adjust the buffer size as needed
    jsonDocument["subject"] = "FROM ESP32";
    jsonDocument["body"] = "🎆🎇 Flame Detected ⚠️⚠️";
    String jsonData;
    serializeJson(jsonDocument, jsonData);
    http.begin("https://server-for-esp32.vercel.app/api/send");
    String jsondata = "{subject:ESP32,body:From esp32}";
    http.addHeader("Content-Type","application/json");
    int httpCode = http.POST(jsonData);
    if (httpCode > 0){
      String resp = http.getString();
      Serial.println();
      Serial.println(resp);
    }
    http.end();
  }else{
    Serial.println("WiFi disconnected. Please Restart");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  int num = digitalRead(IR);
  Serial.println(num);
  if (num == 0){
    digitalWrite(LED,1);
    digitalWrite(BUZZ,1);
    send_email();
  }
  digitalWrite(LED,0);
  digitalWrite(BUZZ,0);
  delay(500);
}
