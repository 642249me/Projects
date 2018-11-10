const int buttonPin = 2;     
const int ledPin1 =  13;      
const int ledPin2 = 12;
int del = 6000;
// variables will change:
int staat;
int vorig=LOW;
int tijd=0;
int vtijd=0;
int toer=0;
int vtoer = 0;
int toerenteller = 0;
int maxtoer = 0;
int cst=0;
int keer=0;


void setup() {
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(19200);
}

void loop(){
  // read the state of the pushbutton value:
  staat = digitalRead(buttonPin);
 
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  
  if (staat == LOW && vorig==LOW) {
    vtijd =tijd;
    tijd = millis();
    toerenteller = toerenteller + 1;
    digitalWrite(ledPin1,HIGH); 
    digitalWrite(ledPin2,LOW);
    delayMicroseconds(del);
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW);
    vorig=HIGH;
  } 
  
  if (staat == HIGH && vorig==HIGH) {
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    delayMicroseconds(del);
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW);
    vorig=LOW;
  }
  
  vtoer = maxtoer - 60;
  toer = 60000/(tijd - vtijd);
  
  if (toerenteller == 50 ) {
    Serial.println(toer);
    toerenteller = 0;
    if (toer >= maxtoer - 30) {
      del = del - 100;
      Serial.println(del);
      cst = 0;
      if(toer > maxtoer){
          maxtoer = toer;
      }
    }
    
   else if (toer < vtoer && cst == 0){
      del = del +100;
      cst=1;
      Serial.println(del);
    }
  }
}
