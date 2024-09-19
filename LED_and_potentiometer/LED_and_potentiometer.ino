int pPin = A1;
int LEDpin = 10;
int potVal;
float LEDval;
int delayTime = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(pPin, INPUT);
  pinMode(LEDpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  potVal = analogRead(pPin);
  LEDval = (225./1023.)*potVal;
  analogWrite(LEDpin, LEDval);
  Serial.println(potVal);
  //delay(delayTime);
}
