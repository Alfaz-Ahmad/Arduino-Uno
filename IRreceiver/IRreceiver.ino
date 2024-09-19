# include<IRremote.h>

int TransPin = 0;
int LEDPin = 4;
int delayTime = 1000;


void setup() {
  // put your setup code here, to run once:
  pinMode(LEDPin, OUTPUT);
  Serial.begin(9600);
  IrReceiver.begin(TransPin, ENABLE_LED_FEEDBACK);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(LEDPin, HIGH);
  delay(delayTime);
  digitalWrite(LEDPin, LOW);
  delay(delayTime);
  if(IrReceiver.decode()){
    Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX); // Print "old" raw data
      IrReceiver.printIRResultShort(&Serial); // Print complete received data in one line
      // IrReceiver.printIRSendUsage(&Serial);   // Print the statement required to send this data
      IrReceiver.resume(); // Enable receiving of the next value
  }
}
