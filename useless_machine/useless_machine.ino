#include <Servo.h>

Servo myServo;
int ServoPin = 9;
int btnPin = 10;
int ledPin = 8;
int ServoPosHigh = 90;
int ServoPosLow = 6;
int skewTime = 200;
int delayTime;
int btnVal;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  myServo.attach(ServoPin);
  myServo.write(ServoPosHigh);
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT);
  digitalWrite(btnPin, HIGH);
  btnVal = digitalRead(btnPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(btnVal);
  myServo.write(ServoPosHigh);
  if(btnVal != digitalRead(btnPin)){
    digitalWrite(ledPin, HIGH);
    while(btnVal != digitalRead(btnPin)){
    }
    delayTime = random(1,7) * 500;
    Serial.println(delayTime);
    delay(delayTime);
    myServo.write(ServoPosLow);
    delay(skewTime);
    myServo.write(ServoPosHigh);
    digitalWrite(ledPin, LOW);
    delay(skewTime);
  }
}
