# include<Stepper.h>
int stepsPerRevolution = 2048;
int motSpeed = 10;
int delayT = 500;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
}

void loop() {
  // put your main code here, to run repeatedly:
  myStepper.step(stepsPerRevolution);
  delay(delayT);
  myStepper.step(-1*stepsPerRevolution);
  delay(delayT);
}
