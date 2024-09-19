#include <LiquidCrystal.h>
int rs=12;
int en=11;
int vo = 6;
int d4=5;
int d5=4;
int d6=3;
int d7=2;
int plotVal = 75;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
  // put your setup code here, to run once:
  analogWrite(vo, plotVal);
lcd.begin(16,2);
}
 
void loop() {
lcd.setCursor(0,0);
lcd.print("Watch me Count");
for (int j=1;j<=10;j=j+1){
  lcd.setCursor(0,1);
  lcd.print(j);
  delay(500);
}
 lcd.clear();
}