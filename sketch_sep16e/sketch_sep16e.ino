#include <Arduino.h>
#include <WiFi.h>
#include <ESPAsyncWebServer.h>
#include <ESP32Servo.h>

const char* ssid = "YourSSID";
const char* password = "YourPassword";

const int servoPin = 2; // GPIO pin where the servo is connected
Servo myservo; // Create a servo object

AsyncWebServer server(80);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Initialize the servo
  myservo.attach(servoPin);

  // Serve a simple HTML page to control the servo
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    String html = "<html><body>";
    html += "<h1>Servo Control</h1>";
    html += "<form action='/setServo' method='POST'>";
    html += "Angle (0 to 180): <input type='text' name='angle'><br>";
    html += "<input type='submit' value='Set Angle'>";
    html += "</form>";
    html += "</body></html>";
    request->send(200, "text/html", html);
  });

  // Handle the POST request to set the servo angle
  server.on("/setServo", HTTP_POST, [](AsyncWebServerRequest *request){
    String angleStr = request->arg("angle");
    int angle = angleStr.toInt();
    if (angle >= 0 && angle <= 180) {
      myservo.write(angle);
      request->send(200, "text/plain", "Servo angle set to " + angleStr);
    } else {
      request->send(400, "text/plain", "Invalid angle");
    }
  });

  server.begin();
}

void loop() {
  // Your main code here
}
