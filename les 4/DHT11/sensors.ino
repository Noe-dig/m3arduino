void ReadDHT11() {
  float temperature = round(dht.readTemperature() * 10) / 10;
  float humidity = round(dht.readHumidity() * 10) / 10;
  float heatIndex = round(dht.computeHeatIndex(temperature, humidity, false) * 10) / 10;
  int ldrValue = analogRead(LDR_Pin);

  if (isnan(temperature) || isnan(humidity) || isnan(heatIndex)) {
    Serial.println("DHT11 sensor error");
  } else {
    Temperature = temperature;
    Humidity = humidity;
    HeatIndex = heatIndex;

    Serial.println("Temp: " + String(Temperature) + "°C");
    Serial.println("Humidity: " + String(Humidity) + "%");
    Serial.println("HeatIndex: " + String(HeatIndex) + "°C");
    Serial.println("LDR: " + String(ldrValue));

    if(ldrValue >= 500){
      digitalWrite(D6, HIGH);
      digitalWrite(D5, HIGH);
      digitalWrite(D3, HIGH);
    }
    else {
      digitalWrite(D5, HIGH);
    }
  }
}

void CreateJSON() {
  StaticJsonDocument<256> doc;
  doc["temperature"] = Temperature;
  doc["humidity"] = Humidity;
  doc["heat_index"] = HeatIndex;
  doc["ldr_value"] = analogRead(LDR_Pin);

  String jsonOutput;
  serializeJson(doc, jsonOutput);
  
  Serial.println(jsonOutput);
}
