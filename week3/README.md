# Week 3 – Analog Sensing & Integrated Systems

## 📌 Overview

Week 3 focuses on analog sensing, time-based measurement, and multi-module system integration.

This week marks the transition from digital input/output logic to real-world sensor interpretation and dynamic actuator control.

Three progressively advanced projects were developed to explore analog measurement, physics-based sensing, and structured embedded system design.

---

## 🧠 Core Concepts Covered

- Analog-to-Digital Conversion (10-bit ADC)
- Voltage divider design
- Signal mapping and scaling
- PWM (Pulse Width Modulation)
- Sensor smoothing (averaging)
- Ultrasonic time-of-flight measurement
- Speed of sound calculation
- Distance-based control logic
- Multi-module hardware integration
- Modular embedded architecture

---

## 📂 Projects Completed

### 1️⃣ Automatic LED Brightness Control (LDR + PWM)

A light-dependent brightness control system using a photoresistor (LDR).

- Converted resistance changes into measurable voltage
- Used Arduino’s 10-bit ADC (0–1023 range)
- Mapped sensor values to PWM output (0–255)
- Applied signal smoothing through averaging
- Implemented dynamic brightness adjustment

This project introduced analog sensing and sensor-to-actuator mapping.

---

### 2️⃣ Smart Distance Monitor (Ultrasonic + LED)

A distance-based LED control system using an HC‑SR04 ultrasonic sensor.

- Measured echo pulse duration using microseconds
- Applied real-world physics formula for distance calculation
- Converted distance to LED brightness using PWM
- Structured code using modular functions

This project introduced time-based sensing and physics-based computation.

---

### 3️⃣ Smart Distance Monitor with LCD Display

An integrated monitoring system combining:

- Ultrasonic sensor
- PWM-controlled LED
- I2C LCD display

The system:

- Displays real-time distance in centimeters
- Shows proximity status (CLOSE / MEDIUM / FAR)
- Adjusts LED brightness based on distance
- Uses modular architecture for clean system separation

This project marks the first fully integrated multi-component embedded system built during the learning journey.

---

## 📈 Progression Within the Week

Week 3 evolved from:

Analog Measurement  
→ Signal Processing  
→ Physical Modeling  
→ Sensor Mapping  
→ Multi-Module Integration  

The complexity increased gradually while maintaining clean structure and real hardware validation.

---

## ✅ Learning Outcome

By the end of Week 3, the following skills were strengthened:

- Understanding of analog sensor behavior
- Practical voltage divider analysis
- ADC range interpretation and calibration
- PWM-based actuator control
- Ultrasonic distance measurement
- Time-of-flight computation
- Hardware debugging and calibration
- Clean modular embedded design
- Structured GitHub documentation workflow

Week 3 represents the shift from simple control logic to integrated sensor-based intelligent systems.