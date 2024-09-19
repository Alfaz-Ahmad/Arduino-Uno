int myNum;
int buzzPin = 10;
int delay_Time = 2000;
String msg = "Enter a number: ";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(msg);
  while(Serial.available() == 0){

  }
  myNum = Serial.parseInt();
  if(myNum > 10){
    digitalWrite(buzzPin, HIGH);
    delay(delay_Time);
    digitalWrite(buzzPin, LOW);
  }
  Serial.println();
}
