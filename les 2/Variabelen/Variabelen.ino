void setup() {
  pinMode (D0, OUTPUT);
  pinMode (D1, OUTPUT);
  pinMode (D2, OUTPUT); 
  
  Serial.begin(115200);

}

void loop() {
    

    int A = random(999);
    int B = random(999);
    int C = random(999);
    int D = random(999);

    Serial.println(A);
    Serial.println(B);
    Serial.println(C);
    Serial.println(D);

  if(A > B){
    digitalWrite(D0, HIGH);
  }
    else if(C > A){
      digitalWrite(D0, HIGH);   
    }

  if(C > A){
    digitalWrite(D1, HIGH);
  }
    else if(B > A){
      digitalWrite(D1, HIGH);   
    }

  if(B > C && B > A && A > C){
    digitalWrite(D2, HIGH);
  }

  if(D > A && D > B && D > C){
    for (int i = 0; i <= 255; i++){
      digitalWrite(D0, HIGH);
      digitalWrite(D1, HIGH);
      digitalWrite(D2, HIGH);
      delay(100);
    }
  }
}
