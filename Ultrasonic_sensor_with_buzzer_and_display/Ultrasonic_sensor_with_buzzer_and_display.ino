#include "SevSeg.h"
SevSeg sevseg;

int trigPin = 12;
int echoPin = 11;
int buzzPin = 10;
int pingTravelTime;
int buzzDelay;

float distance;

int d1Pin = A0;
int d2Pin = A1;
int d3Pin = A2;
int d4Pin = A3;
int aPin = 9;
int bPin = 8;
int cPin = 7;
int dPin = 6;
int ePin = 5;
int fPin = 4;
int gPin = 3;
int dpPin = 2;

unsigned long previousMillis = 0;
unsigned long currentMillis;

unsigned long sevpreviousMillis = 0;
unsigned long sevcurrentMillis;
int sevIntervel = 500;

float val = 0;

void setup() {
  byte Digits = 4;
  byte DPins[] = {d1Pin, d2Pin, d3Pin, d4Pin};
  byte SPins[] = {aPin, bPin, cPin, dPin, ePin, fPin, gPin, dpPin};
  byte type = COMMON_ANODE;
  bool res = false;
  bool delayup = false;
  bool leadZero = false;
  bool decimal = false;

  pinMode(buzzPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  sevseg.begin( type, Digits, DPins, SPins, res, delayup, leadZero, decimal);
  sevseg.setBrightness(0);
  sevseg.setChars("----");
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pingTravelTime = pulseIn(echoPin, HIGH);

  distance = pingTravelTime/58.2;
  if(distance >= 7){
    sevcurrentMillis = millis();
    if(sevcurrentMillis - sevpreviousMillis >= sevIntervel){
      sevseg.setNumberF(distance, 1);
      sevpreviousMillis = sevcurrentMillis;
    }
    Serial.print("Distance: ");
    Serial.println(distance);
    buzzDelay = distance*10;
    if(distance < 100 && distance > 7){
      tone(buzzPin, 4500, 100);
    }else{
      buzzDelay = 1000;
    }
    currentMillis = millis();
    while(currentMillis - previousMillis < buzzDelay){
      sevcurrentMillis = millis();
      if(sevcurrentMillis - sevpreviousMillis >= sevIntervel){
        if(distance >= 7){
          sevseg.setNumberF(distance, 1);
        }else{
          sevseg.setChars("----");
        }
        sevpreviousMillis = sevcurrentMillis;
      }
      currentMillis = millis();
      sevseg.refreshDisplay();
    }
    previousMillis = currentMillis;
  }else{
    Serial.println(distance);
    sevseg.setChars("----");
  }
  sevseg.refreshDisplay();
}