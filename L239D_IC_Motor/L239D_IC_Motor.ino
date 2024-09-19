int speedPin = 5;
int dirPin1 = 4;
int dirPin7 = 3;
int mSpeed = 255;

void setup() {
  // put your setup code here, to run once:
  pinMode(speedPin, OUTPUT);
  pinMode(dirPin1, OUTPUT);
  pinMode(dirPin7, OUTPUT);
  Serial.begin(9600);;
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(dirPin1, HIGH);
  digitalWrite(dirPin7, LOW);
  analogWrite(speedPin, mSpeed);
  Serial.println(mSpeed);
}
