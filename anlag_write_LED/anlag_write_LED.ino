#define LED 9
#define INTENS 10

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  // analogWrite(LED, 50);
  for(i=0;i<256;i++){
    analogWrite(LED, i);
    delay(10);
  }
  for(i=255;i>=0;i--){
    analogWrite(LED, i);
    delay(10);
  }
  delay(500);
}
