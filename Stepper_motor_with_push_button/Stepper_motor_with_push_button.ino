# include<Stepper.h>
int stepsPerRevolution = 2048;
int motSpeed = 10;
int delayT = 500;
int btnVal;
int preVal;
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);
int btnPin = 2;
bool chance = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myStepper.setSpeed(motSpeed);
  pinMode(btnPin, INPUT);
  digitalWrite(btnPin, HIGH);
  preVal = digitalRead(btnPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(preVal);
  Serial.print(" ");
  Serial.println(digitalRead(btnPin));
  btnVal = digitalRead(btnPin);
  if(btnVal != preVal && !chance){
    preVal = btnVal;
    chance = true;
  }
  if(btnVal != preVal && chance){
    stepsPerRevolution *= -1;
    preVal = btnVal;
    chance = false;
  }
  Serial.println(stepsPerRevolution);
  myStepper.step(stepsPerRevolution);
}
