int pin1 = 6;
int pin2 = 5;
int pin3 = 3;
char Color[20]; // Character array to store color

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
}

void loop() {
  Serial.print("Enter a color: ");
  
  while (Serial.available() == 0) {
    // Wait until input is available
  }
  
  // Read input into color array
  Serial.readBytesUntil('\n', Color, sizeof(Color));
  
  // Remove newline character from the color array
  Color[strcspn(Color, "\r\n")] = 0;
  
  Serial.println("Received color: " + String(Color)); // Debugging statement
  
  // Compare the received color with predefined colors
  if (strcmp(Color, "red") == 0) {
    Serial.println("Setting color to red");
    analogWrite(pin1, 255);
    analogWrite(pin2, 0);
    analogWrite(pin3, 0);
  } else if (strcmp(Color, "blue") == 0) {
    Serial.println("Setting color to blue");
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
    analogWrite(pin3, 255);
  } else if (strcmp(Color, "green") == 0) {
    Serial.println("Setting color to green");
    analogWrite(pin1, 0);
    analogWrite(pin2, 255);
    analogWrite(pin3, 0);
  } else if (strcmp(Color, "cyan") == 0) {
    Serial.println("Setting color to cyan");
    analogWrite(pin1, 0);
    analogWrite(pin2, 255);
    analogWrite(pin3, 255);
  } else if (strcmp(Color, "gray") == 0) {
    Serial.println("Setting color to gray");
    analogWrite(pin1, 160);
    analogWrite(pin2, 160);
    analogWrite(pin3, 160);
  } else if (strcmp(Color, "white") == 0) {
    Serial.println("Setting color to white");
    analogWrite(pin1, 255);
    analogWrite(pin2, 255);
    analogWrite(pin3, 255);
  }else if (strcmp(Color, "magenta") == 0) {
    Serial.println("Setting color to white");
    analogWrite(pin1, 255);
    analogWrite(pin2, 0);
    analogWrite(pin3, 100);
  }else if (strcmp(Color, "yellow") == 0) {
    Serial.println("Setting color to white");
    analogWrite(pin1, 127);
    analogWrite(pin2, 127);
    analogWrite(pin3, 0);
  } else {
    Serial.println("Invalid color: " + String(Color)); // Debugging statement
    // Set LEDs to off
    analogWrite(pin1, 0);
    analogWrite(pin2, 0);
    analogWrite(pin3, 0);
  }
  
  Serial.println(); // Newline for formatting
  
  // Clear the color array
  memset(Color, 0, sizeof(Color));
}
