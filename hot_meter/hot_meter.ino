const int sensor=A0;
const float threshold = 30.0;

int green = 4;
int yellow = 3; 
int red = 2; 


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);

pinMode(green, OUTPUT);
pinMode(red, OUTPUT);
pinMode(yellow, OUTPUT);




digitalWrite(green, LOW);
digitalWrite(red, LOW);
digitalWrite(yellow, LOW);

}

void loop() {
  // put your main code here, to run repeatedly:

  int SensorVal = analogRead(sensor);

  float voltage = SensorVal/1024.0 * 5.0; 

  float temperature = (voltage -.5)*100; 

  
  Serial.print("Sensor is reading: ");
  Serial.print(SensorVal);
  Serial.print("\t");
  Serial.print("voltage");Serial.print(voltage);
  Serial.print("\t");
  Serial.print("temperature: "); Serial.print(temperature); 
  Serial.print("\n");



  if(temperature < threshold ) {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);


    Serial.println("BAD");
    }
  else if (temperature < threshold+ 3)
  { digitalWrite(yellow, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(red, HIGH);

  Serial.println("May be");
    }
  else if (temperature > threshold + 3){
    digitalWrite(green, HIGH);
    digitalWrite(red, HIGH);
    digitalWrite(yellow, HIGH);

    Serial.println("Emmm"); 
    
    }
  
 
  

}
