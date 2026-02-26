#include <Arduino.h>
#line 1 "C:\\Users\\msi pulse\\week2\\button_led\\button_led.ino"
// Button + LED example using a pull‑down resistor on D2

// Pressing the button (5 V → D2) turns the LED ON.
// Releasing it (D2 pulled down to GND) turns the LED OFF.

const int ledPin    = 8;  // LED on digital pin 8
const int buttonPin = 2;   // Button on digital pin 2

#line 9 "C:\\Users\\msi pulse\\week2\\button_led\\button_led.ino"
void setup();
#line 14 "C:\\Users\\msi pulse\\week2\\button_led\\button_led.ino"
void loop();
#line 9 "C:\\Users\\msi pulse\\week2\\button_led\\button_led.ino"
void setup() {
  pinMode(ledPin, OUTPUT);   // set LED pin as output
  pinMode(buttonPin, INPUT); // D2 reads voltage from button node
}

void loop() {
  int buttonState = digitalRead(buttonPin); // 0 = released, 1 = pressed

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH); // LED on
  } else {
    digitalWrite(ledPin, LOW);  // LED off
  }
}
