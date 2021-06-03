#include<Servo.h>
Servo myServo;


const int piezo = A0;
const int switchPin = 2;
const int greenLed = 3;
const int BlueLed = 4; 
const int redLed = 5;

int knockVal;
int switchVal; 

const int quietKnock = 10; 
const int loudKnock = 100; 

boolean locked = false; 
int numberOfknocks = 0; 



void setup() {
  // put your setup code here, to run once:
  myServo.attach(9);
  pinMode(BlueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  Serial.begin(9600);
  digitalWrite(greenLed, HIGH);
  myServo.write(0);
  Serial.println("The box is unlocked");

}

void loop() {
  // put your main code here, to run repeatedly:

  if (locked == false) {
    switchVal = digitalRead(switchPin); 
    if (switchVal == HIGH) {
    locked = true; 
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
    myServo.write(90);
    Serial.println("The box is locked");
    delay(1000); 
    }
}
  if (locked == true ) {
    knockVal = analogRead(piezo);
    if (numberOfknocks < 3 && knockVal > 0 ) {
      if (checkForKnock(knockVal) == true) {
        numberOfknocks++; 
        }
      Serial.println(3-numberOfknocks);
      Serial.println("more knock to go"); 
      }
    if (numberOfknocks >= 3) {
      locked = false; 
      myServo.write(0); 
      delay(20); 
      digitalWrite(greenLed, HIGH);
      digitalWrite(redLed, LOW);
      Serial.println("The box is unlocked !");
      numberOfknocks = 0;
      }
  }
    
}
boolean checkForKnock(int value) {
if (value > quietKnock && value < loudKnock) {
digitalWrite(BlueLed, HIGH);
delay(50);
digitalWrite(BlueLed, LOW);
Serial.print("Valid Knock of Value");
Serial.println(value); 
return true; 
}
else {
 Serial.print("Bad knock ");
 Serial.println(value);
 return false;  
  }
}
