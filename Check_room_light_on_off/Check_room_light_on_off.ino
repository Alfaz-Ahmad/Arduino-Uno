int lightPin = A0;
int redPin = 2;
int greenPin = 3;
int lightVal;
int delayTime = 100;

void setup() {
  // put your setup code here, to run once:
  pinMode(lightPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  lightVal = analogRead(lightPin);
  Serial.println(lightVal);
  if(lightVal >= 512){
    digitalWrite(redPin, LOW);
    digitalWrite(greenPin, HIGH);
  }else{
    digitalWrite(greenPin, LOW);
    digitalWrite(redPin, HIGH);
  }
  delay(delayTime);
}
