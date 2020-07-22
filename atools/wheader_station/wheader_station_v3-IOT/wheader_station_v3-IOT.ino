#include <Arduino.h>
#include <DHTesp.h>
#include <Hash.h>
#include "ESP8266WiFi.h"
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>

#define DTH_PIN 14
#define BUILD_LED 2

int temperature = 0;
int humidity = 0;
int heatIndex = 0;
int dewPoint = 0;
int absoluteHum = 0;
int comfortRatio = 0;

unsigned long previousMillis = 0;    // will store last time DHT was updated
// Updates DHT readings every 20 seconds
const long interval = 20000;

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
    request->send_P(200, "text/plain", String(temperature).c_str());
  });
  server.on("/humidity", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(humidity).c_str());
  });

  server.on("/heatindex", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(heatIndex).c_str());
  });

  server.on("/temphiha", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/plain", String(comfortRatio).c_str());
  });

  // Start server
  server.begin();
  Serial.print("done");
  pinMode(BUILD_LED, OUTPUT);
}

String processor(const String& var){
  Serial.println(var);
  if(var == "TEMPERATURE")
  {
    return String(temperature);
  }
  else if(var == "HUMIDITY")
  {
    return String(humidity);
  }
  else if(var == "HEATIDX")
  {
    return String(heatIndex);
  }
  else if(var == "DEVPOINT")
  {
    return String(dewPoint);
  }
   else if(var == "ABSOLUTEHUM")
  {
    return String(absoluteHum);
  }
   else if(var == "TEMPHIHA")
  {
    return String(comfortRatio);
  }
  
  return String();
}


void loop() {

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {

    digitalWrite(BUILD_LED, LOW); // turn the LED on (HIGH is the voltage level)
    
    previousMillis = currentMillis;    
    float newT = dht.getTemperature();

    Serial.print("Reading DHT:");
    if (isnan(newT)) 
    {
      Serial.println("Failed to read from DHT sensor!");
    }
    else 
    {
      temperature = (int)newT;
      Serial.print("Temperature: ");
      Serial.print(temperature);
      Serial.print(" *C ");   
    }
    
    // Read Humidity
    float newH = dht.getHumidity();    
    if (isnan(newH)) 
    {Serial.println("Failed to read from DHT sensor!");
      
    }
    else 
    {
      humidity = (int)newH;
      Serial.print("Humidity: ");
      Serial.print(humidity);
      Serial.print(" % ");
    }

    float newhic = dht.computeHeatIndex(temperature, humidity, false);    
    heatIndex = (int)newhic;
    Serial.print("Heat Index: ");
    Serial.print(heatIndex);
    Serial.print(" *C ");   

    float newdewPoint = dht.computeDewPoint(temperature, humidity, false);    
    dewPoint = (int)newdewPoint;
    Serial.print("Dev Point: ");
    Serial.print(dewPoint);
    Serial.print(" *C ");  

    float newaHum = dht.computeAbsoluteHumidity(temperature, humidity, false);    
    absoluteHum = (int)newaHum;
    Serial.print("AbsHum: ");
    Serial.print(absoluteHum);
    Serial.print(" % ");

    float comfortNew = dht.computePerception(temperature, humidity, false);    
    comfortRatio = (int)comfortNew;
    Serial.print("Temperature HiHa: ");
    Serial.print(comfortRatio);
    Serial.print(" *C ");  


    Serial.println("Send to IOT");
    WiFiClient client;
    int retries = 5;
    while(!client.connect(getServer(), 80) && (retries-- > 0)) {
      Serial.print(".");
    }
    Serial.println();
    if(!client.connected()) {
     Serial.println("Failed to connect, going back to sleep");
    }
    
    Serial.println("Request resource: " + getTSUrl()); 
    String fullRequest = String("GET ") + getTSUrl() + 
                  "&field1=" + humidity + 
                  "&field2=" + temperature +
                  "&field3=" + heatIndex +
                  "&field4=" + dewPoint +
                  "&field5=" + absoluteHum +
                  "&field6=" + comfortRatio +
                  " HTTP/1.1\r\n" +
                  "Host: " + getServer() + "\r\n" + 
                  "Connection: close\r\n\r\n";

    Serial.println(fullRequest);
    client.print(fullRequest);


    int timeout = 5 * 10; // 5 seconds             
    while(!client.available() && (timeout-- > 0)){
      delay(100);
    }
    if(!client.available()) {
     Serial.println("No response, going back to sleep");
    }
    
    while(client.available()){
      Serial.write(client.read());
    }
  
    Serial.println("\nclosing connection");
    client.stop();

    digitalWrite(BUILD_LED, HIGH); // turn the LED off by making the voltage LOW
  }  
}
