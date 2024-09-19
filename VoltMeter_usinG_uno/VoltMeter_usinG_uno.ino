// C++ code
//
int readPin = A3;
int readVal;
float V2 = 0;
int time = 1000;
void setup()
{
  pinMode(readPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  readVal = analogRead(readPin);
  V2 = (5.0/1023.0)*readVal;
  Serial.println(V2);
  delay(time);
}