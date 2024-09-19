// int latchPin = 11;
// int clockPin = 9;
// int dataPin = 12;
// int delay_time = 500;

// byte LEDs = 0b00000000;

// void setup() {
//   // put your setup code here, to run once:
//   Serial.begin(9600);
//   pinMode(latchPin, OUTPUT);
//   pinMode(dataPin, OUTPUT);
//   pinMode(dataPin, OUTPUT);
// }

// void loop() {
//   // put your main code here, to run repeatedly:
//   digitalWrite(latchPin, LOW);
//   shiftOut(dataPin, clockPin, LSBFIRST, LEDs);
//   digitalWrite(latchPin, HIGH);
//   delay(delay_time);
//   Serial.println(LEDs, BIN);
//   LEDs = LEDs + 1;
// }


int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=500;
 
byte LED1s=0b00000000;
 
 
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(latchPin,OUTPUT);
pinMode(dataPin,OUTPUT);
pinMode(clockPin,OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(latchPin,LOW);
shiftOut(dataPin,clockPin,LSBFIRST,LED1s);
digitalWrite(latchPin,HIGH);
 
Serial.println(LED1s,BIN);
delay(dt);
LED1s=LED1s+1;
}