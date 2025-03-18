#include <ArduinoJson.h>

JsonDocument doc;
char jsonOut[128];

void setup() {
  pinMode (D1, OUTPUT);
  pinMode (D2, OUTPUT);
  pinMode (D3, OUTPUT);

  Serial.begin(115200);
  Serial.println("check");
}
void loop() {
  CreateJSON();
  
  int ldr_value = analogRead(A0);
  int randomSpeed = random(100, 500);

  if (ldr_value < 500){
    for (int i = 0; i <=255; i++){
      digitalWrite(D2, HIGH);
      delay(randomSpeed);
      digitalWrite(D2, LOW);
      delay(1000);
    }
  }
}

bool lichtGehalteFunction(int ldr_value){
  
  bool lichtGehalte = false;

  if (ldr_value > 500){
    lichtGehalte = true; 
  }
  return lichtGehalte;
}

void CreateJSON(){
//  doc["licht"] = knipperLicht();

  serializeJson(doc, jsonOut);
  serializeJson(doc, Serial);
}
