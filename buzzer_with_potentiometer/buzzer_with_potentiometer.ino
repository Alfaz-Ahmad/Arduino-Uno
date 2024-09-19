int buzzPin = 5;
int potPin = A0;
int potval;
float slope;
int buzzRate;
int fixRate = 1;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potval = analogRead(potPin);
  slope = (9940./1023.)*potval;
  buzzRate = slope+60;
  Serial.println(buzzRate);
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(buzzRate);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(buzzRate);
}
