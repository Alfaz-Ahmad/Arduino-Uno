#include <LiquidCrystal.h>;

const int rs = 12, en = 11, d4 = 7, d5 = 4, d6 = 3, d7 = 2, ct=9;
int plotPin = A1, redPin = 10, bluePin = 6, greenPin = 5;
LiquidCrystal mylcd(rs, en, d4, d5, d6, d7);
int plotVal, delayTime = 100;
double val, redVal, greenVal;

void setup() {
pinMode(plotPin, INPUT);
pinMode(redPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(greenPin, OUTPUT);
analogWrite(ct, 50);
mylcd.begin(16, 2);
Serial.begin(9600);
}

void loop() {
	plotVal = analogRead(plotPin);
  Serial.println(plotVal);
  	val = (5./1023.)*plotVal;
  	redVal = (255./5.)*val;
  	greenVal = (255./5.)*(5-val);
  	analogWrite(redPin, redVal);
  	analogWrite(greenPin, greenVal);
  	analogWrite(bluePin, 0);
  	mylcd.clear();
  	mylcd.print("V = ");
  	mylcd.print(val);
  	delay(delayTime);
}