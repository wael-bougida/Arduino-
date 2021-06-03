
const int greenLEDPin = 9;
const int blueLEDPin = 10;
const int redLEDPin = 11;


const int redSensorPin = A0;
const int greenSensorPin = A1;
const int blueSensorPin = A2;

int redValue = 0;
int blueValue = 0;
int greenValue = 0;

int redSensorValue = 0;
int blueSensorValue = 0;
int greenSensorValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(greenLEDPin, OUTPUT);
  pinMode(blueLEDPin, OUTPUT);
  pinMode(redLEDPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
redSensorValue = analogRead(redSensorPin);
delay(5);
greenSensorValue = analogRead(greenSensorPin);
delay(5);
blueSensorValue = analogRead(blueSensorPin);
delay(5);


Serial.print("Raw sensor \t red: ");
Serial.print(redSensorValue);

Serial.print("Raw sensor \t green: ");
Serial.print(greenSensorValue);
Serial.print("\n");

Serial.print("Raw sensor \t blue: ");
Serial.print(blueSensorValue);




redValue = redSensorValue/4;
greenValue = greenSensorValue/4;
blueValue = blueSensorValue/4; 


Serial.print("Mapped sensor Values: \t red: ");
Serial.print(redValue);

Serial.print(" \t green: ");
Serial.print(greenValue);
Serial.print(" \t blue: ");
Serial.print(blueValue);










analogWrite(redLEDPin, redValue);

analogWrite(greenLEDPin, greenValue);

analogWrite(blueLEDPin, blueValue);


}
