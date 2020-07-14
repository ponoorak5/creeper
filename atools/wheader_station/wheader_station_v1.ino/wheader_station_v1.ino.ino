#include <Arduino.h>
#include <DHTesp.h>
#include <Hash.h>
#include "ESP8266WiFi.h"
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#define DTH_PIN 14
#define BUILD_LED 2

float temp = 0.0;
float hum = 0.0;
float heatIndex = 0.0;
float dewPoint = 0.0;
float absoluteHum = 0.0;
float comfortRatio = 0.0;

unsigned long previousMillis = 0;    // will store last time DHT was updated
// Updates DHT readings every 10 seconds
const long interval = 10000;

DHTesp dht;
AsyncWebServer server(80);





void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);
  while(!Serial) { }

  Serial.println("Device Started");
  Serial.println("-------------------------------------");
  Serial.println("Running DHT!");
  Serial.println("-------------------------------------");
  dht.setup(DTH_PIN, DHTesp::DHT11);
  Serial.println(dht.getStatusString());
  Serial.println("");
  Serial.println("-------------------------------------");
  Serial.print("Running WIFI! ");
  Serial.println(getWifiSSID());
  Serial.println("-------------------------------------");
  WiFi.begin(getWifiSSID(), getWifiPassword());
  Serial.println(WiFi.status());
  while (WiFi.status() != WL_CONNECTED) 
  {
     delay(500);
     Serial.print("*");
  }
  
  Serial.println("");

  Serial.println("WiFi connection Successful");
  Serial.print("The IP Address of ESP8266 Module is: ");
  Serial.println(WiFi.localIP());// Print the IP address

  Serial.println("");

  Serial.println("starting web server...");
  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", getIndexPage(), processor);
  });
  server.on("/temperature", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(temp).c_str());
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(hum).c_str());
  });

  // Start server
  server.begin();
  Serial.print("done");
  pinMode(BUILD_LED, OUTPUT);
}

String processor(const String& var){
  //Serial.println(var);
  if(var == "TEMPERATURE"){
    return String(temp);
  }
  else if(var == "HUMIDITY"){
    return String(hum);
  }
  return String();
}


void loop() {

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {

    digitalWrite(BUILD_LED, LOW); // turn the LED on (HIGH is the voltage level)
    
    // save the last time you updated the DHT values
    previousMillis = currentMillis;
    // Read temperature as Celsius (the default)
    float newT = dht.getTemperature();
    // Read temperature as Fahrenheit (isFahrenheit = true)
    //float newT = dht.readTemperature(true);
    // if temperature read failed, don't change t value
    if (isnan(newT)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      temp = newT;
      Serial.println(temp);
    }
    // Read Humidity
    float newH = dht.getHumidity();
    // if humidity read failed, don't change h value 
    if (isnan(newH)) {
      Serial.println("Failed to read from DHT sensor!");
    }
    else {
      hum = newH;
      Serial.println(hum);
    }

    digitalWrite(BUILD_LED, HIGH); // turn the LED off by making the voltage LOW
  }  
}
