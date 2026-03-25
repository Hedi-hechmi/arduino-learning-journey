# LED Blinking – Week 1 (Built-in LED)

## 📌 Overview
This project demonstrates basic digital output control using the built-in LED on the Arduino Uno.
The LED is toggled ON and OFF every 2 seconds using a blocking delay.

## 🎯 Objectives
- Understand digital HIGH (~5V) and LOW (~0V)
- Learn how to configure output pins
- Understand blocking timing using `delay()`

## 🧰 Hardware Used
- Arduino Uno (built-in LED on pin 13)
- USB cable

No external components were required.

## ⚙️ How It Works

In `setup()`:
- The built-in LED pin is configured as OUTPUT.

In `loop()`:
- The LED is set HIGH (ON)
- The program waits 2 seconds using `delay(2000)`
- The LED is set LOW (OFF)
- The program waits 2 seconds again

This produces a square wave signal with:

- Period = 4 seconds  
- Frequency = 0.25 Hz  
- Duty Cycle = 50%

## 💻 Code

```cpp
// Blink the Arduino built-in LED with a delay of 2 seconds

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{