#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define BUTTON 7

byte lastStatus;

unsigned long lastTime = millis();
unsigned long rebounce = 50;

int counter = 0;
int digit0 = 0;
int digit1 = 0;
int digit2 = 0;
int digit3 = 0;
int i;

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
    byte buttonState = digitalRead(BUTTON);
    if(buttonState != lastStatus){
      lastTime = millis();
      lastStatus = buttonState;
      if(buttonState == HIGH){
        counter = (counter+1)%16;
      }
      int val = counter;
      digit0 = val%2;
      val /= 2;
      digit1 = val%2;
      val /= 2;
      digit2 = val%2;
      val /= 2;
      digit3 = val%2;
      val /= 2;
      digitalWrite(pin2, digit0);
      digitalWrite(pin3, digit1);
      digitalWrite(pin4, digit2);
      digitalWrite(pin5, digit3);
    }
  }
}
