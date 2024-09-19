int btn1Pin = 4;
int btn2Pin = 5;
int ledVal;
int ledPin = 9;
int delayT = 50;
int btnState;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(btn1Pin, INPUT);
  pinMode(btn2Pin, INPUT);
  pinMode(ledPin, OUTPUT);
  ledVal = 0;
  btnState = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  // Serial.println(digitalRead(btn1Pin));
  analogWrite(ledPin, ledVal);
  while(digitalRead(btn1Pin)!=btnState){
    if(ledVal < 255){
      ledVal++;
    }
    Serial.println(ledVal);
    analogWrite(ledPin, ledVal);
    delay(delayT);
  }
  while(digitalRead(btn2Pin)!=btnState){
    if(ledVal > 0){
      ledVal--;
    }
    analogWrite(ledPin, ledVal);
    delay(delayT);
  }
}
