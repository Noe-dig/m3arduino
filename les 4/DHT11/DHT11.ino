#include <ArduinoJson.h>
#include "DHT.h"

#define DHTTYPE DHT11
uint8_t DHTPin = D7;
DHT dht(DHTPin, DHTTYPE);

float Temperature, Humidity, HeatIndex;
int LDR_Pin = A0;

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode (D6, OUTPUT);
  pinMode (D5, OUTPUT);
  pinMode (D3, OUTPUT);
}

void loop() {
  ReadDHT11();
  CreateJSON();
  delay(6000);
}
