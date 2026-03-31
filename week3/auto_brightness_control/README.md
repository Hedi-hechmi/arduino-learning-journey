# Automatic LED Brightness Control – Week 3

## 📌 Overview
This project implements an automatic LED brightness control system using a photoresistor (LDR) and PWM output.

The LED brightness dynamically adjusts based on ambient light conditions:

- Dark environment → LED becomes brighter  
- Bright environment → LED becomes dimmer  

The system uses a voltage divider, Arduino’s 10-bit ADC, signal smoothing (averaging), and PWM-based brightness control.

---

## 🎯 Objectives
- Understand analog input using `analogRead()`
- Learn how voltage dividers convert resistance into voltage
- Understand Arduino’s 10-bit ADC (0–1023 range)
- Implement PWM brightness control using `analogWrite()`
- Map sensor range to actuator range
- Apply basic signal smoothing (averaging)
- Build and test the system on real hardware

---

## 🧰 Hardware Used
- Arduino Uno  
- Photoresistor (LDR)  
- 10kΩ resistor (voltage divider)  
- LED  
- 220Ω resistor (current limiting)  
- Breadboard  
- Jumper wires  

---

## 🔌 Circuit Description

### LDR Voltage Divider

5V → LDR → A0 → 10kΩ → GND

The LDR and 10kΩ resistor form a voltage divider.

- Bright light → LDR resistance decreases → A0 voltage increases  
- Darkness → LDR resistance increases → A0 voltage decreases  

This converts light intensity into a measurable voltage.

---

### LED (PWM Output)

Pin 9 (PWM) → 220Ω resistor → LED → GND

Pin 9 is used because it supports PWM output.

---

## 🧠 System Logic

1. Read analog voltage from A0 (range: 0–1023).
2. Take multiple readings and average them to reduce noise.
3. Map measured light range to PWM brightness range (0–255).
4. Invert the brightness value so dark = brighter LED.
5. Apply brightness using `analogWrite()`.

Measured real hardware range:

- Dark ≈ 12  
- Bright ≈ 1004  

---

## ⚙️ Behavior

| Environment | ADC Value | LED Brightness |
|-------------|-----------|----------------|
| Dark        | Low       | High           |
| Bright      | High      | Low            |

The system reacts smoothly thanks to averaging.

---

## ✅ Learning Outcome

This project demonstrates:

- Practical analog sensing  
- Voltage divider analysis  
- ADC interpretation  
- PWM brightness control  
- Sensor-to-actuator mapping  
- Basic signal smoothing  
- Real hardware calibration  

This marks the transition from digital-only systems to analog signal processing and dynamic output control.

---

## 💻 Full Source Code

```cpp
const int ldrPin = A0;
const int ledPin = 9;

const int minLight = 12;     
const int maxLight = 1004;   

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {

  long total = 0;

  // Average 10 readings for smoothing
  for (int i = 0; i < 10; i++) {
    total += analogRead(ldrPin);
    delay(5);
  }

  int lightValue = total / 10;

  int brightness = map(lightValue, minLight, maxLight, 0, 255);
  brightness = constrain(brightness, 0, 255);
  brightness = 255 - brightness;

  analogWrite(ledPin, brightness);

  delay(100);
}