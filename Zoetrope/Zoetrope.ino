const int Controlpin1 = 2; 
const int Controlpin2 = 3;
const int enablePin = 9;
const int directionSwitchPin = 4;
const int onOffSwitchStateSwitchPin = 5; 
const int potPin = A0;

int onOffSwitchState = 0; 
int previousOnOffSwitchState = 0;
int directionSwitchState = 0; 
int previousDirectionSwitchState = 0; 




int motorEnabled = 0; 
int motorSpeed = 0; 
int motorDirection  = 1; 


void setup() {
  // put your setup code here, to run once:
pinMode(directionSwitchPin, INPUT);
pinMode(onOffSwitchStateSwitchPin, INPUT);
pinMode(Controlpin1, OUTPUT);
pinMode(Controlpin2, OUTPUT);
pinMode(enablePin, OUTPUT);


Serial.begin(9600);

digitalWrite(enablePin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
onOffSwitchState = digitalRead(onOffSwitchStateSwitchPin); 
delay(1);
directionSwitchState = digitalRead(directionSwitchPin); 
motorSpeed = analogRead(potPin)/4;



if(onOffSwitchState != previousOnOffSwitchState) {
  if (onOffSwitchState == HIGH) {
    motorEnabled = !motorEnabled;
    //S//erial.println("motor enabled");
    }
  }
if(directionSwitchState != previousDirectionSwitchState) {
  if (directionSwitchState == HIGH) {
    motorDirection = !motorDirection ;
    //Serial.println("direction enabled");

    }
}
if (motorDirection == 1){
  digitalWrite(Controlpin1, HIGH);
  digitalWrite(Controlpin2, LOW);
  Serial.println("direction 1 ");

}
else {
  digitalWrite(Controlpin1, LOW);
  digitalWrite(Controlpin2, HIGH);
  Serial.println("direction 2 ");

 }
if(motorEnabled == 1){
  analogWrite(enablePin, motorSpeed);
  //Serial.println("motor enabled");

}
else {
  analogWrite(enablePin, 0);
  
  }
 previousDirectionSwitchState = directionSwitchState;
 previousOnOffSwitchState = onOffSwitchState;
}
  
   
