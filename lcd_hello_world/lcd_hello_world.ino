#include <LiquidCrystal.h>;

int plotVal = 75; 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2, vo = 6;;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  lcd.begin(16, 2);
  analogWrite(vo, plotVal);
  Serial.begin(9600);
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Hello");
  // mylcd.setCursor(0,1);
  // mylcd.print("Tesla Tesla");
  // mylcd.scrollDisplayLeft();
  // delay(500);
}