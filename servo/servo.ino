#include <Servo.h>

int servoPin = 9;
int servoPos = 90;
Servo myServo;
int delayT = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.print("What Angle: ");
  // while(Serial.available() == 0){

  // }
  // servoPos = Serial.parseInt();
  // Serial.println(servoPos);


  myServo.write(servoPos);
  Serial.println(servoPos);
  // if(servoPos > 5){
  //   servoPos -= 1;
  // }else{
  //   servoPos = 90;
  // }
  // delay(delayT);
}
