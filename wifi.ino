#include<WiFi.h>
#include<ESPAsyncWebSrv.h>

AsyncWebServer server(80);
void notFound(AsyncWebServerRequest * request){
  String message = "Page Not Found";
  request -> send(404, "text/plain", message);
}

char webpage[] PROGMEM = R"=====(
  <!DOCTYPE html>
<html>
<body>
    <center>
        <h1>Control Your LED remotely</h1>
        <h3>LED 1</h3>
        <button type="button" onclick="window.location = 'http://'+location.hostname+'/led1/on'">ON</button>
        <button type="button" onclick="window.location = 'http://'+location.hostname+'/led1/off'">OFF</button>
        <h3>LED 2</h3>
        <button type="button" onclick="window.location = 'http://'+location.hostname+'/led2/on'">ON</button>
        <button type="button" onclick="window.location = 'http://'+location.hostname+'/led2/off'">OFF</button>
    </center>
</body>
</html>
)=====";

void setup() {
  // put your setup code here, to run once:
  delay(1000);
  Serial.begin(115200);
  Serial.println("Configuring Access Point...");
  WiFi.softAP("ESP32","");

  Serial.println("AP IP Address...");
  Serial.println(WiFi.softAPIP());
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);

  server.on("/", [](AsyncWebServerRequest * request){
  request -> send_P(200, "text/html", webpage);
  });

  server.on("/led1/on",HTTP_GET, [](AsyncWebServerRequest * request){
    digitalWrite(2,HIGH);
  request -> send_P(200, "text/html", webpage);
  });
  server.on("/led1/off",HTTP_GET, [](AsyncWebServerRequest * request){
    digitalWrite(2,LOW);
  request -> send_P(200, "text/html", webpage);
  });
  server.on("/led2/on",HTTP_GET, [](AsyncWebServerRequest * request){
    digitalWrite(4,HIGH);
  request -> send_P(200, "text/html", webpage);
  });
  server.on("/led2/off",HTTP_GET, [](AsyncWebServerRequest * request){
    digitalWrite(4,LOW);
  request -> send_P(200, "text/html", webpage);
  });
  server.onNotFound(notFound);
  server.begin();
}

void loop() {
}
