int switchState = 0; 
const int sensorPin = A0;
const float baselineTemp = 20.0; 
void setup() {
  // put your setup code here, to run once:
/*pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(2, INPUT);*/
Serial.begin(9600);
for (int pinNumber = 2; pinNumber<5; pinNumber++){
  pinMode(pinNumber, OUTPUT);
  digitalWrite(pinNumber, LOW);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
/*switchState = digitalRead(2);
if (switchState == LOW){
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);  
  }
else { 
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  delay(250);
   digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  delay(250);
*/
int sensorVal = analogRead(sensorPin);
Serial.print("VALUE: ");
Serial.print(sensorVal);
float Voltage = (sensorVal/1024.0)*5.0;
Serial.print("Volts: ");
Serial.print("degrees C: ");
float temperature = (Voltage - .5) * 10;
Serial.println(temperature);

if (temperature< baselineTemp+2){
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);}
  else if (temperature >= baselineTemp +2 && temperature < baselineTemp+4){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    }
   else if (temperature >= baselineTemp +4 && temperature < baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);
    }
    else if (temperature >= baselineTemp+6){
    digitalWrite(2, HIGH);
    digitalWrite(3, HIGH);
    digitalWrite(4, HIGH);
    }
    delay(1);
   


  

}
