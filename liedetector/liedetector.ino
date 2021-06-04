const int green = 4;
const int yellow = 3;
const int red = 2;

int conductivity = 0; 



void setup()
{
  Serial.begin(9600);
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  digitalWrite(green, HIGH);
  delay(500);
  digitalWrite(yellow, HIGH);
  delay(500);
  digitalWrite(red, HIGH);
  delay(500);
}

void loop()
{
  conductivity = analogRead(A0);
  if (conductivity > 600)
  {
    digitalWrite(red, HIGH);
    digitalWrite(green, LOW);
    digitalWrite(yellow, LOW);
    delay(50);
  }
  /*else
  {
    digitalWrite(green, LOW);
    delay(500);
  }*/
  else if (conductivity > 200)
  {
    digitalWrite(green, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(yellow, LOW);
    delay(50);
  }
  /*else
  {
    digitalWrite(red, LOW);
    delay(50);
  }*/
  else if (conductivity > 45)
  {
    digitalWrite(yellow, HIGH);
    digitalWrite(red, LOW);
    digitalWrite(green, LOW);
    delay(50);
  }
  /*else
  {
    digitalWrite(yellow, LOW);
    delay(50);
  }*/

  Serial.println(conductivity);
  delay(20);
}
