const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin1 =  13;      // the number of the LED pin
const int ledPin2 = 12;
int del = 2;
// variables will change:
int staat;
int vertraag=0;
int vorig=LOW;


void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  // read the state of the pushbutton value:
  staat = digitalRead(buttonPin);
 
  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  
  if (staat == LOW && vorig==LOW) {     
    // turn LED on:    
    digitalWrite(ledPin1, HIGH); 
    digitalWrite(ledPin2, LOW);
    delay(del);
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW);
    vorig=HIGH;
  } 
  if(staat == HIGH && vorig==HIGH) {
    // turn LED off:
    digitalWrite(ledPin1, LOW);
    digitalWrite(ledPin2, HIGH);
    delay(del);
    digitalWrite(ledPin1, LOW); 
    digitalWrite(ledPin2, LOW);
    vorig=LOW;
  }
}
