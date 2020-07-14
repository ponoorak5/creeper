#include <DHTesp.h>
#include "ESP8266WiFi.h"
#define DTH_PIN 14
DHTesp dht;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(2000);
  dht.setup(DTH_PIN, DHTesp::DHT11);
  Serial.println(dht.getStatusString());
}

void loop() {
  float t = dht.getTemperature();
  float h = dht.getHumidity();
 
  // Sprawdzamy czy są odczytane wartości
  if (isnan(t) || isnan(h))
  {
    // Jeśli nie, wyświetlamy informację o błędzie
    Serial.println("Blad odczytu danych z czujnika");
  } else
  {
    // Jeśli tak, wyświetlamy wyniki pomiaru
    Serial.print("Wilgotnosc: ");
    Serial.print(h);
    Serial.print(" % ");
    Serial.print("Temperatura: ");
    Serial.print(t);
    Serial.println(" *C");
  }
  delay(1000);
}
