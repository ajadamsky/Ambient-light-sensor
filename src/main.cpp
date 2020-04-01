#include <Arduino_MKRENV.h>

#define INPUT_PIN 9 // BUTTON
int ledPin = A0; // LED

void setup() {
  Serial.begin(9600);

  pinMode(INPUT_PIN, INPUT_PULLUP); // BUTTON
  pinMode (ledPin, OUTPUT); // LED
  while (!Serial);

  if (!ENV.begin()) {
    Serial.println("Failed to initialize MKR ENV shield!");
    while (1);
  }
}

void loop() {

if (digitalRead(INPUT_PIN) == LOW) { // Pressed button

  float illuminance = ENV.readIlluminance();
  Serial.print("Light = ");
  Serial.print(illuminance);
  Serial.println(" lx");

  int value = analogRead(INPUT_PIN);
  value = map(illuminance, 400, 500, 255, 0); // Adjusting brightnes on LED. In the dark room: LED on, no light: LED off
  analogWrite(ledPin, value);
  Serial.println();
  delay(100);
 }
}