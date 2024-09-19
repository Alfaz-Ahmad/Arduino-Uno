int d1Pin = 13;
int d2Pin = 12;
int d3Pin = 11;
int d4Pin = 10;
int aPin = 9;
int bPin = 8;
int cPin = 7;
int dPin = 6;
int ePin = 5;
int fPin = 4;
int gPin = 3;
int dpPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(d1Pin, OUTPUT);
  pinMode(d2Pin, OUTPUT);
  pinMode(d3Pin, OUTPUT);
  pinMode(d4Pin, OUTPUT);

  pinMode(aPin, OUTPUT);
  pinMode(bPin, OUTPUT);
  pinMode(cPin, OUTPUT);
  pinMode(dPin, OUTPUT);
  pinMode(ePin, OUTPUT);
  pinMode(fPin, OUTPUT);
  pinMode(gPin, OUTPUT);
  pinMode(dpPin, OUTPUT);

  digitalWrite(aPin, LOW);
  digitalWrite(bPin, LOW);
  digitalWrite(cPin, LOW);
  digitalWrite(dPin, LOW);
  digitalWrite(ePin, LOW);
  digitalWrite(fPin, LOW);
  digitalWrite(gPin, LOW);
  digitalWrite(dpPin, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(d1Pin, HIGH);
  digitalWrite(d2Pin, HIGH);
  digitalWrite(d3Pin, HIGH);
  digitalWrite(d4Pin, HIGH);

  digitalWrite(aPin, LOW);
  digitalWrite(bPin, LOW);
  digitalWrite(cPin, LOW);
  digitalWrite(dPin, LOW);
  digitalWrite(ePin, LOW);
  digitalWrite(fPin, LOW);
  digitalWrite(gPin, HIGH);
  digitalWrite(dpPin, HIGH);
  delay(1000);
}
