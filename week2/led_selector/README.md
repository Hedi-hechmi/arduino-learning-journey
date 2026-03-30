# LED Selector – Week 2

## 📌 Overview
This project implements a button-controlled LED mode selector using rising-edge detection, software debouncing, and non-blocking timing logic.

Each button press cycles through four LED operating modes:

- Mode 0 → LED OFF  
- Mode 1 → LED ON  
- Mode 2 → Slow Blink (1000 ms interval)  
- Mode 3 → Fast Blink (200 ms interval)  

The system is designed to operate reliably on real hardware, accounting for mechanical button bounce and ensuring responsive behavior during LED blinking.

---

## 🎯 Objectives
- Implement reliable button press detection  
- Detect rising-edge transitions (LOW → HIGH)  
- Apply software debouncing (200 ms)  
- Design a simple state machine  
- Implement non-blocking blinking using `millis()`  
- Structure embedded logic modularly  

---

## 🧰 Hardware Used
- Arduino Uno  
- Push button  
- 10kΩ pull-down resistor  
- LED  
- 220Ω resistor  
- Breadboard  
- Jumper wires  

---

## 🔌 Circuit Description

### Button (Pull-Down Configuration)

- One side of button → 5V  
- Other side → Digital Pin 2  
- 10kΩ resistor from Pin 2 → GND  

When pressed:  
Pin reads HIGH.

When released:  
Pin reads LOW.

---

### LED

- Digital Pin 8 → 220Ω resistor → LED → GND  

---

## 🧠 System Design

### Rising-Edge Detection
Mode changes only when the button transitions from LOW to HIGH.

This prevents continuous mode switching while the button is held.

---

### Software Debounce
A 200 ms timing filter prevents multiple triggers from a single mechanical press.

This ensures stable behavior on physical hardware.

---

### State Machine Logic
The `mode` variable cycles from 0 to 3 and wraps back to 0.

This implements a simple circular state machine.

---

### Non-Blocking Blink Function
Blinking is implemented using `millis()` instead of `delay()`.

This allows the system to remain responsive to button input during blinking.

---

## ⚙️ Mode Behavior

| Mode | LED Behavior |
|------|--------------|
| 0 | OFF |
| 1 | ON |
| 2 | Slow Blink (1s) |
| 3 | Fast Blink (200ms) |

---

## ✅ Learning Outcome

This project demonstrates:

- Practical rising-edge detection  
- Software debouncing on real hardware  
- Implementation of a simple state machine  
- Non-blocking timing using `millis()`  
- Modular embedded system structure  

This marks the transition from basic I/O control to structured embedded design.

---

## 💻 Full Source Code

```cpp
const int buttonPin = 2;
const int ledPin = 8;

int mode = 0;

bool buttonState = LOW;
bool lastButtonState = LOW;

unsigned long lastPressTime = 0;
const unsigned long debounceTime = 200;

unsigned long previousMillis = 0;
bool ledState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  // Rising-edge detection
  if (buttonState == HIGH && lastButtonState == LOW) {

    if (millis() - lastPressTime > debounceTime) {
      mode++;
      if (mode > 3) mode = 0;

      Serial.println(mode);
      lastPressTime = millis();
    }
  }

  lastButtonState = buttonState;

  handleMode();
}

void handleMode() {

  switch (mode) {

    case 0:
      digitalWrite(ledPin, LOW);
      break;

    case 1:
      digitalWrite(ledPin, HIGH);
      break;

    case 2:
      blink(1000);
      break;

    case 3:
      blink(200);
      break;
  }
}

void blink(unsigned long interval) {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}