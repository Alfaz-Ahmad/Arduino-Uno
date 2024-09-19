#define LED_PIN 8
#define BUTTON_PIN 7
// https://roboticsbackend.com/arduino-turn-led-on-and-off-with-button/

byte lastButtonState;
byte LedState = LOW;
unsigned long lastTime = millis();
unsigned long rebounce = 50;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  lastButtonState = digitalRead(BUTTON_PIN);
}

void loop() {
  if(millis() - lastTime >= rebounce){
    byte buttonState = digitalRead(BUTTON_PIN);
    if(buttonState != lastButtonState){
      lastTime = millis();
      lastButtonState = buttonState;
      if(buttonState == LOW){
        if(LedState == HIGH){
          LedState = LOW;
        }else{
          LedState = HIGH;
        }
        digitalWrite(LED_PIN, LedState);
      }
    }
  }
}
