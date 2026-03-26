# LED Pattern – Week 1

## 📌 Overview
This project implements multiple LED blinking patterns using modular functions in Arduino.

An external LED connected to digital pin 8 performs different lighting sequences in a continuous loop. The main objective of this project is to structure LED behavior using reusable functions instead of writing all logic directly inside the `loop()` function.

---

## 🎯 Objectives
- Practice digital output control
- Structure embedded code using functions
- Implement different LED timing patterns
- Understand blocking delays using `delay()`

---

## 🧰 Hardware Used
- Arduino Uno
- External LED connected to digital pin 8
- 215Ω resistor
- Breadboard
- Jumper wires

---

## 🔌 Circuit Description
The LED is connected to digital pin 8 through a current-limiting resistor.

- HIGH output (~5V) → LED ON  
- LOW output (~0V) → LED OFF  

Circuit diagrams are available inside:

docs/diagrams/

---

## ⚙️ Program Structure

The LED behavior is divided into modular functions to improve readability and code organization.

### Main Loop Behavior

The program continuously executes three LED patterns:

1️⃣ **Blink Once (1000 ms)**  
- LED ON for 1 second  
- LED OFF for 1 second  

2️⃣ **Flash 3 Times (200 ms)**  
- LED flashes 3 times  
- Each ON and OFF lasts 200 milliseconds  

3️⃣ **Long ON (3000 ms)**  
- LED ON for 3 seconds  
- LED OFF for 3 seconds  

---

## 💻 Full Code

```cpp
const int Ledpin = 8; // LED connected to digital pin 8

void setup()
{
    pinMode(Ledpin, OUTPUT); // Set the LED pin as output
}

void loop()
{
    Blinkonce(1000);    // Blink LED once (1 second ON/OFF)
    flash3times(200);   // Flash LED 3 times (200 ms interval)
    LongOne(3000);      // Long ON (3 seconds)
}

void Blinkonce(int duration)
{
    digitalWrite(Ledpin, HIGH);
    delay(duration);
    digitalWrite(Ledpin, LOW);
    delay(duration);
}

void flash3times(int duration)
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(Ledpin, HIGH);
        delay(duration);
        digitalWrite(Ledpin, LOW);
        delay(duration);
    }
}

void LongOne(int duration)
{
    digitalWrite(Ledpin, HIGH);
    delay(duration);
    digitalWrite(Ledpin, LOW);
    delay(3000);
}