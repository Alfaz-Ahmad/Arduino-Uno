void setup() {
  // put your setup code here, to run once:
  pinMode(4, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int i = 0;
  while(i<3){
    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(4, LOW);
    delay(100);
    i++;
  }

  digitalWrite(4, LOW);
  delay(400);

  i = 0;
  while(i<3){
    digitalWrite(4, HIGH);
    delay(400);
    digitalWrite(4, LOW);
    delay(100);
    i++;
  }

  digitalWrite(4, LOW);
  delay(400);

  i = 0;
  while(i<3){
    digitalWrite(4, HIGH);
    delay(200);
    digitalWrite(4, LOW);
    delay(100);
    i++;
  }

  digitalWrite(4, LOW);
  delay(400);

  i = 0;
  while(i<3){
    digitalWrite(4,HIGH);
    delay(200);
    digitalWrite(4, LOW);
    delay(100);
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(4, LOW);
    delay(100);
    i++;
  }

  digitalWrite(4, LOW);
  delay(4000);
}
