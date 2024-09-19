int pin1 = 6;
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
  if(Color.equals("red")){
    Serial.print("yes");
    analogWrite(pin1, 255);
    analogWrite(pin2, 0);
    analogWrite(pin3, 0);
  }else if(Color == "blue"){
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
    analogWrite(pin3, 255);
  }else if(Color == "green"){
    analogWrite(pin1, 0);
    analogWrite(pin2, 255);
    analogWrite(pin3, 0);
  }else if(Color == "cyan"){
    analogWrite(pin1, 0);
    analogWrite(pin2, 255);
    analogWrite(pin3, 255);
  }else if(Color == "gray"){
    analogWrite(pin1, 160);
    analogWrite(pin2, 160);
    analogWrite(pin3, 160);
  }else if(Color == "white"){
    analogWrite(pin1, 255);
    analogWrite(pin2, 255);
    analogWrite(pin3, 255);
  }else{
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
    analogWrite(pin3, 0);
  }
  Serial.println();
}
