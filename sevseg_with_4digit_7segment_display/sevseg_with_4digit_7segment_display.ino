#include "SevSeg.h"
SevSeg sevseg;


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
  byte Digits = 4;
  byte DPins[] = {d1Pin, d2Pin, d3Pin, d4Pin};
  byte SPins[] = {aPin, bPin, cPin, dPin, ePin, fPin, gPin, dpPin};
  byte type = COMMON_ANODE;
  bool res = false;
  bool delayup = false;
  bool leadZero = false;
  bool decimal = false;

  sevseg.begin( type, Digits, DPins, SPins, res, delayup, leadZero, decimal);
  sevseg.setBrightness(0);
  // sevseg.setChars("--");

}

void loop() {
  // put your main code here, to run repeatedly:
    // sevseg.blank();
    // sevseg.refreshDisplay();
    int val = 320;
    sevseg.setNumber(val, 2);
    sevseg.refreshDisplay();
}
