int hall0;
int hall1;
int hall2;
int knop;
int knop2;
int vorig = 6;
int del = 20;
int vtijd=0;
int tijd=0;
int toer=0;
int toerenteller=0;

void setup() {
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  Serial.begin(19200);
}

void loop() { 
  hall0 = digitalRead(A0);
  hall1 = digitalRead(A1);
  hall2 = digitalRead(A2);
  knop = digitalRead(3);
  knop2 = digitalRead(2);
  digitalWrite(0, LOW);
  digitalWrite(1, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  
  if(knop == HIGH && del > 7){
    del = del-1;
    Serial.println(del);
    digitalWrite(A4, HIGH);
    delay(50);
    digitalWrite(A4, LOW);
  }
  
  if(knop2 == HIGH && del <20){
    del = del + 1;
    Serial.println(del);
    digitalWrite(A3, HIGH);
    delay(50);
    digitalWrite(A3, LOW);
  }
  
  if (vorig == 6 && hall0 == HIGH)
  {
    vtijd =tijd;
    tijd = millis();
    toerenteller = toerenteller + 1;
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    
    delay(del);
    
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    vorig = 1;
  }
  
  if (vorig == 1 && hall1 == LOW)
  {
    digitalWrite(0, LOW);
    digitalWrite(1, LOW);
    
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
    
    delay(del);
    
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    vorig = 2;  
  }
  
  if (vorig == 2 && hall2 == HIGH)
  {
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    
    delay(del);
    
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    
    vorig = 3;  
  }
  
  if (vorig == 3 && hall0 == LOW)
  {
    digitalWrite(0, HIGH);
    digitalWrite(1, HIGH);
    
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    
    delay(del);
    
    digitalWrite(0, LOW);
    digitalWrite(1, HIGH);
    
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    
    vorig = 4;  
  }
  
  if (vorig == 4 && hall1 == HIGH)
  {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    
    delay(del);
    
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    
    vorig = 5;  
  }
  
  if (vorig == 5 && hall2 == LOW)
  {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    
    digitalWrite(6, HIGH);
    digitalWrite(7, HIGH);
    
    delay(del);
    
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);
    
    vorig = 6;  
  }
  
  if (toerenteller == 25 ) {
    toer = 60000/(tijd - vtijd);
    Serial.println(toer);
    toerenteller = 0;
    }
}
