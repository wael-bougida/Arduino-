const int switchPin = 2; 
const int motorPin = 9;
int switchState = 0;




void setup() {
  // put your setup code here, to run once:
pinMode(motorPin, OUTPUT);
pinMode(switchPin, INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
switchState = digitalRead(switchPin);
if (switchState == HIGH){
  digitalWrite(motorPin, HIGH);
  Serial.println("switch pressed");
  }
else  {
  digitalWrite(motorPin, LOW);
  }
}
