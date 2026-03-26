# Button LED Control – Week 2

## 📌 Overview
This project demonstrates basic digital input handling using a push button and controlling an LED based on user interaction.

An external push button connected to digital pin 2 controls an LED connected to digital pin 8.  
When the button is pressed, the LED turns ON.  
When the button is released, the LED turns OFF.

This implementation uses a pull‑down resistor configuration.

---

## 🎯 Objectives
- Understand digital input using `digitalRead()`
- Learn how pull‑down resistors work
- Control an output device based on user input
- Implement simple conditional logic in embedded systems

---

## 🧰 Hardware Used
- Arduino Uno
- Push button
- External LED
- 220Ω resistor (for LED)
- 10kΩ resistor (pull‑down for button)
- Breadboard
- Jumper wires

---

## 🔌 Circuit Description

### Button Wiring (Pull‑Down Configuration)

- One side of button → 5V
- Other side → Digital Pin 2
- 10kΩ resistor connects Digital Pin 2 → GND

This ensures:
- Button released → Pin reads LOW (0V)
- Button pressed → Pin reads HIGH (5V)

### LED Wiring
- Digital Pin 8 → 220Ω resistor → LED → GND

---

## ⚙️ Program Logic

1. Configure LED pin as OUTPUT
2. Configure button pin as INPUT
3. Continuously read button state
4. If button is pressed → LED ON
5. If button is released → LED OFF

---

## 💻 Full Code

```cpp
// Button + LED example using a pull‑down resistor on D2
// Pressing the button (5V → D2) turns the LED ON.
// Releasing it (D2 pulled down to GND) turns the LED OFF.

const int ledPin    = 8;  // LED on digital pin 8
const int buttonPin = 2;  // Button on digital pin 2

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}