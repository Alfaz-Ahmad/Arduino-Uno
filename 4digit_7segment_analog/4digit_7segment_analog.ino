#include "SevSeg.h"
SevSeg sevseg;


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

int val = 0;

void setup() {
  byte Digits = 4;
  byte DPins[] = {d1Pin, d2Pin, d3Pin, d4Pin};
  byte SPins[] = {aPin, bPin, cPin, dPin, ePin, fPin, gPin, dpPin};
  byte type = COMMON_ANODE;
  bool res = false;
  bool delayup = false;
  bool leadZero = false;
  bool decimal = false;
  Serial.begin(9600);

  sevseg.begin( type, Digits, DPins, SPins, res, delayup, leadZero, decimal);
  sevseg.setBrightness(0);
  sevseg.setNumber(val, 1);
}

void loop() {
  Serial.print("Enter a Number: ");
  while(Serial.available() == 0){
    sevseg.refreshDisplay();
  }
  val = Serial.parseInt();
  sevseg.setNumber(val, 1);
  Serial.println(val);
  sevseg.refreshDisplay();
  delay(1000);
}
