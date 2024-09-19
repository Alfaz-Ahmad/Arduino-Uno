// C++ code
//

int PIN = A2;
int redLED = 7;
int readVal;
float val;
int time = 250;

void setup()
{
  Serial.begin(9600);
  pinMode(redLED, OUTPUT);
  
}

void loop(){
  readVal = analogRead(PIN);
  val = (5.0/1023.0)*readVal;
  Serial.println(val);
  if(val >= 4.0){
    digitalWrite(redLED, HIGH);
  }else{
    digitalWrite(redLED, LOW);
  }
  delay(time);
}