int trigPin = 12;
int echoPin = 11;
int pingTravelTime;
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  pingTravelTime = pulseIn(echoPin, HIGH);

  distance = pingTravelTime/58.2;

  Serial.println(distance);
}
