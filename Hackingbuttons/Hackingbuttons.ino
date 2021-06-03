const int optoPin = 2; 



void setup() {
  // put your setup code here, to run once:
pinMode(optoPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(optoPin, HIGH);
delay(15);
digitalWrite(optoPin, LOW);
delay(21000);
}
