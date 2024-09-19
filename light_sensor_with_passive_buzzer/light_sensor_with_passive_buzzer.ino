int photoPin = A0;
int buzzPin = 7;
int plotVal;
float slope;
int buzzTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(photoPin, INPUT);
  pinMode(buzzPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  plotVal = analogRead(photoPin);
  slope = (99940.0/1023.0)*plotVal;
  buzzTime = slope+60;
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(buzzTime);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(buzzTime);
}
