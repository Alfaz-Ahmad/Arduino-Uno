int potPin = A0;
int readVal;
int buzzPin = 8;

void setup() {
  // put your setup code here, to run once:
  pinMode(potPin, INPUT);
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  readVal = analogRead(potPin);
  if(readVal > 1000){
    digitalWrite(buzzPin, HIGH);
  }else{
    digitalWrite(buzzPin, LOW);
  }
}
