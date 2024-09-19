// C++ code
//

int PIN = A2;
int readVal;
float val;
int time = 250;

void setup()
{
  Serial.begin(9600);
}

void loop(){
  readVal = analogRead(PIN);
  val = (5.0/1023.0)*readVal;
  Serial.println(val);
  delay(time);
}