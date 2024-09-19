int latchPin=11;
int clockPin=9;
int dataPin=12;
int dt=500;
byte LED1s = 0;
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(latchPin,OUTPUT);
  pinMode(dataPin,OUTPUT);
  pinMode(clockPin,OUTPUT);
}
 
void loop() {
  // put your main code here, to run repeatedly:
  if(LED1s == 0 || LED1s >= 256){
    LED1s == 0;
    digitalWrite(latchPin,LOW);
    shiftOut(dataPin,clockPin,LSBFIRST,LED1s);
    digitalWrite(latchPin,HIGH);
    while(Serial.available() == 0){

    }
    LED1s = Serial.parseInt();
  }
  digitalWrite(latchPin,LOW);
  shiftOut(dataPin,clockPin,LSBFIRST,LED1s);
  digitalWrite(latchPin,HIGH);
 
  Serial.println(LED1s,BIN);
  delay(dt);
  LED1s=LED1s*2;
}