#include <DHTesp.h>
#include "ESP8266WiFi.h"

DHTesp dht;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);
   
  // Wait for serial to initialize.
  while(!Serial) { }

  Serial.println("Device Started");
  Serial.println("-------------------------------------");
  Serial.println("Running DHT!");
  Serial.println("-------------------------------------");
  dht.setup(4, DHTesp::DHT11);
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
}

int timeSinceLastRead = 0;
void loop() {
  // Report every 2 seconds.
  if(timeSinceLastRead > 6000) {
    // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
    float h = dht.getHumidity();
    // Read temperature as Celsius (the default)
    float t = dht.getTemperature();

    // Check if any reads failed and exit early (to try again).
    if (isnan(h) || isnan(t)) {
      Serial.println("Failed to read from DHT sensor!");
      timeSinceLastRead = 0;
      return;
    }
    
    ComfortState state;
    
    float hic = dht.computeHeatIndex(t, h, false);
    float dpc = dht.computeDewPoint(t, h, false);
    float ahc = dht.computeAbsoluteHumidity(t, h, false);
    float crc = dht.getComfortRatio(state, t, h, false);
    byte pc = dht.computePerception(t, h, false);

    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C ");    
    Serial.print("Heat index: ");
    Serial.print(hic);
    Serial.print(" *C ");    
    Serial.print("Dev Point: ");
    Serial.print(dpc);
    Serial.print(" ");
    Serial.print("Absolute humidity in g/m³: ");
    Serial.print(ahc);
    Serial.print(" ");
    Serial.print("Comfort ratio: ");
    Serial.print(crc);
    Serial.print(" ");
    Serial.print("Comfort state: ");
    Serial.print(state);
    Serial.print(" ");
    Serial.print("Perception: ");
    Serial.println(pc);

    timeSinceLastRead = 0;

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
    String fullRequest = String("GET ") + getTSUrl() + "&field1=" + h + "&field2=" + t +
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
  }
  delay(100);
  timeSinceLastRead += 100;
}
