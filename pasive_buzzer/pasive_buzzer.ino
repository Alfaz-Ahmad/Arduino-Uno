int buzzPin = 10;
int buzzT1 = 1000;
int buzzT2 = 1000000;


void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzPin, HIGH);
  delayMicroseconds(buzzT1);
  digitalWrite(buzzPin, LOW);
  delayMicroseconds(buzzT2);
}
