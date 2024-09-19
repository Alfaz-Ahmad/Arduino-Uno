// // class Button {
// //     private:
// //         bool _state;
// //         uint8_t _pin;

// //     public:
// //         Button(uint8_t pin) : _pin(pin) {}

// //         void begin() {
// //             pinMode(_pin, INPUT_PULLUP);
// //             _state = digitalRead(_pin);
// //         }

// //         bool isReleased() {
// //             bool v = digitalRead(_pin);
// //             if (v != _state) {
// //                 _state = v;
// //                 if (_state) {
// //                     return true;
// //                 }
// //             }
// //             return false;
// //         }
// // };


// // Button myButton(10);
// int val = 0;
// static bool press = false;

// void setup() {
//     pinMode(10, INPUT);
//     pinMode(13, OUTPUT);
//     Serial.begin(9600);
// }

// void loop() {
//     val = digitalRead(10);
//     delay(1000);
//     if(val == HIGH){
//       Serial.println("yes");
//       digitalWrite(13, HIGH);
//     }else{
//       digitalWrite(13, LOW);
//     }
//     // else{
//     //   press = false;
//     //   Serial.println("No");
//     // }
//     // if (myButton.isReleased()) {
//     //     Serial.println(F("Released"));
//     // }
// }
/*
  Button

  Turns on and off a light emitting diode(LED) connected to digital pin 13,
  when pressing a pushbutton attached to pin 2.

  The circuit:
  - LED attached from pin 13 to ground through 220 ohm resistor
  - pushbutton attached to pin 2 from +5V
  - 10K resistor attached to pin 2 from ground

  - Note: on most Arduinos there is already an LED on the board
    attached to pin 13.

  created 2005
  by DojoDave <http://www.0j0.org>
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/Button
*/

// constants won't change. They're used here to set pin numbers:
const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 13;    // the number of the LED pin

// variables will change:
int buttonState = 0;  // variable for reading the pushbutton status

void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed. If it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
