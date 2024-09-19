
# include <DHT.h>
#define Type DHT11
int sensePin = 2;
DHT HT(sensePin, Type);
float humidity;
float tempC;
float tempF;
int setTime = 50;
int delayTime = 500;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  HT.begin();
  delay(setTime);
}

void loop() {
  // put your main code here, to run repeatedly:
  humidity = HT.readHumidity();
  tempC = HT.readTemperature();
  tempF = HT.readTemperature(true);
  Serial.print("Humidity: ");
  Serial.println(humidity);
  Serial.print("Temperature: ");
  Serial.print(tempC);
  Serial.println("C");
  delay(delayTime);
}
