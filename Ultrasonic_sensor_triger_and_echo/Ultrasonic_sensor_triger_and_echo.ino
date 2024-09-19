int trigPin = A0;
int echoPin = A1;
int pingTravelTime;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  analoglWrite(trigPin, 0);
  delayMicroseconds(10);
  analogWrite(trigPin, HIGH);
  delayMicroseconds(10);
  analogWrite(trigPin, 0);
  pingTravelTime = pulseIn(echoPin, HIGH);
  Serial.println(pingTravelTime);
  delayMicroseconds(25);
}
