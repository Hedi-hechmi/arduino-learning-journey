# Smart Distance Monitor – Week 3

## 📌 Overview

This project implements a distance-based LED brightness control system using an ultrasonic sensor (HC‑SR04).

The LED brightness dynamically changes depending on how close an object is to the sensor:

- Close object → LED becomes brighter  
- Far object → LED becomes dimmer  

The system measures the time-of-flight of ultrasonic waves and converts it into physical distance using the speed of sound. The measured distance is then mapped to PWM brightness.

---

## 🎯 Objectives

- Understand ultrasonic time-of-flight measurement  
- Convert echo pulse duration into physical distance  
- Apply real-world physics (speed of sound)  
- Map distance to PWM brightness  
- Use PWM (`analogWrite`) for dynamic LED control  
- Structure embedded code using modular functions  

---

## 🧰 Hardware Used

- Arduino Uno  
- HC‑SR04 Ultrasonic Sensor  
- LED  
- 220Ω resistor (LED current limiting)  
- Breadboard  
- Jumper wires  

---

## 🔌 Circuit Description

### Ultrasonic Sensor (HC‑SR04)

- VCC → 5V  
- GND → GND  
- TRIG → Pin 9  
- ECHO → Pin 10  

### LED

- Pin 6 (PWM) → 220Ω resistor → LED → GND  

Pin 6 is used because it supports PWM output.

---

## 🔬 How It Works

1. Arduino sends a short 10µs pulse to the TRIG pin.
2. The ultrasonic sensor emits a 40 kHz sound wave.
3. The sound wave reflects off an object.
4. The echo returns to the sensor.
5. The ECHO pin stays HIGH for a duration proportional to the round-trip travel time.
6. Arduino measures that duration using `pulseIn()`.

Distance is calculated using:

Distance (cm) = (Duration × 0.0343) / 2

The division by 2 compensates for the sound traveling to the object and back.

---

## ⚙️ System Behavior

The measured distance is mapped into a PWM brightness range:

- Very close → Bright LED  
- Medium distance → Medium brightness  
- Far distance → Dim LED  

Distance range used:

- 5 cm → Maximum brightness  
- 100 cm → Minimum brightness  

Values outside this range are constrained for stability.

---

## ✅ Learning Outcome

This project demonstrates:

- Ultrasonic sensing and time-based measurement  
- Practical application of speed of sound physics  
- Microsecond timing using `pulseIn()`  
- Mapping sensor values to actuator outputs  
- PWM brightness control  
- Modular embedded system structure  

This project builds on previous work with PWM and analog processing and introduces physics-based sensing and control.

---

## 💻 Full Source Code

```cpp
const int trigPin = 9;
const int echoPin = 10;
const int ledPin  = 6;

float minDistance = 5.0;     
float maxDistance = 100.0;   

void setup() {
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  float distance = readDistance();
  int brightness = calculateBrightness(distance);

  analogWrite(ledPin, brightness);

  delay(100);
}

// ------------------
// Read Distance
// ------------------
float readDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);

  float distance = duration * 0.0343 / 2;

  Serial.println(distance);

  return distance;
}

// ------------------
// Convert Distance → Brightness
// ------------------
int calculateBrightness(float distance) {

  int brightness = map(distance, minDistance, maxDistance, 255, 0);
  brightness = constrain(brightness, 0, 255);

  return brightness;
}