#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define BUTTON 7

byte lastStatus;

unsigned long lastTime = millis();
unsigned long rebounce = 10;

int counter = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(pin5, OUTPUT);
  pinMode(BUTTON, INPUT);
  lastStatus = 0;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(millis() - lastTime >= rebounce){
    byte buttonState = digitalRead(BUTTON_PIN);
    if(buttonState != lastStatus){
      lastTime = millis();
      lastStatus = buttonState;
      if(buttonState == HIGH){
        counter = (counter+1)%16;
      }
      if(counter == 0){
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        digitalWrite(pin5, LOW);
      }else if(counter == 1){
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        digitalWrite(pin5, LOW);        
      }else if(counter == 2){
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        digitalWrite(pin5, LOW);
      }else if(counter == 3){
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        digitalWrite(pin5, LOW);
      }else if(counter == 4){
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        digitalWrite(pin5, LOW);
      }else if(counter == 5){
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        digitalWrite(pin5, LOW);
      }else if(counter == 6){
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, HIGH);
        digitalWrite(pin5, LOW);
      }else if(counter == 7){
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, HIGH);
        digitalWrite(pin5, LOW);
      }else if(counter == 8){
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        digitalWrite(pin5, HIGH);
      }else if(counter == 9){
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        digitalWrite(pin5, HIGH);        
      }else if(counter == 10){
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        digitalWrite(pin5, HIGH);
      }else if(counter == 11){
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, LOW);
        digitalWrite(pin5, HIGH);
      }else if(counter == 12){
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        digitalWrite(pin5, HIGH);
      }else if(counter == 13){
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, HIGH);
        digitalWrite(pin5, HIGH);
      }else if(counter == 14){
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, HIGH);
        digitalWrite(pin5, HIGH);
      }else if(counter == 15){
        digitalWrite(pin2, HIGH);
        digitalWrite(pin3, HIGH);
        digitalWrite(pin4, HIGH);
        digitalWrite(pin5, HIGH);
      }else{
        digitalWrite(pin2, LOW);
        digitalWrite(pin3, LOW);
        digitalWrite(pin4, LOW);
        digitalWrite(pin5, LOW);
      }
    }
  }
}
