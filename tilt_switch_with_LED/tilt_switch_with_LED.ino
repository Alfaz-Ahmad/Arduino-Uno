int tiltPin = 2;
int redPin = 5;
int grnPin = 6;
int tiltVal;
int delayT = 50;

void setup() {
  // put your setup code here, to run once:
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
  pinMode(redPin, OUTPUT);
  pinMode(grnPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  tiltVal = digitalRead(tiltPin);
  Serial.println(tiltVal);
  if(tiltVal == 1){
    digitalWrite(grnPin, LOW);
    digitalWrite(redPin, HIGH);
  }else{
    digitalWrite(redPin, LOW);
    digitalWrite(grnPin, HIGH);
  }
  delay(delayT);
}
