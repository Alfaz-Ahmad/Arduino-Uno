int btnPin = 2;
int btnVal;
int delayT = 1000;

void setup() {
  // put your setup code here, to run once:
  pinMode(btnPin, INPUT);
  digitalWrite(btnPin, HIGH);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  btnVal = digitalRead(btnPin);
  Serial.print("Your Button is: ");
  Serial.println(btnVal);
  delay(delayT);
}
