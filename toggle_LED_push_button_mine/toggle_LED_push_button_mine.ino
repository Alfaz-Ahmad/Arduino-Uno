int ledPin = 7;
int btnPin = 12;
int toggle = 0;
int delayT = 50;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(btnPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(btnPin) != 1){
    toggle++;
    digitalWrite(ledPin, toggle%2);
    while(digitalRead(btnPin) == 0){

    }
  }
  delay(delayT);
}
