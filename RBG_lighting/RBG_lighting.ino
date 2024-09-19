int pin1 = 7;
int pin2 = 5;
int pin3 = 3;
String msg1 = "Enter a color: ";
String Color;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(pin1,OUTPUT);
  pinMode(pin2,OUTPUT);
  pinMode(pin3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(msg1);
  while(Serial.available() == 0){

  }
  Color = Serial.readString();
  Serial.print(Color);
  if(strcmp(Color.c_str(), "red") == 0){
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
  }else if(strcmp(Color.c_str(), "blue") == 0){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
  }else if(Color == "green"){
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
  }else{
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    Serial.print("No!");
  }
  digitalWrite(pin1, HIGH);
  delay(1000);
  Serial.println();
}
