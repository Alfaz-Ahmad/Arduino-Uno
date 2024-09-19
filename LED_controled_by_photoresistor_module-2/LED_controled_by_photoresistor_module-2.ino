int phoPin = A0;
int ledPin = 3;
float phoVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(phoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  phoVal = analogRead(phoPin);
  if(phoVal <= 50){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }
}
