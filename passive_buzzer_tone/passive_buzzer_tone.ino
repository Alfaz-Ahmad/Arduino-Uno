int buzzPin = 10;
int highDelay = 50;
int lowDelay = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i=50; i<=1000; i+=50){
    tone(buzzPin, 4500, 100);
    Serial.println(i);
    delay(i);
  }
}
