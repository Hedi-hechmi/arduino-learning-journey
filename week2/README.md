# Week 2 – Digital Input & Interactive Control Systems

## 📌 Overview

Week 2 focuses on digital input handling and interactive embedded system design using push buttons and LEDs.

This week marks the transition from simple output control (Week 1) to responsive systems where user input directly affects system behavior.

Two projects were implemented to demonstrate increasing complexity and architectural improvement.

---

## 🧠 Concepts Covered

- Digital input using `digitalRead()`
- Pull-down resistor configuration
- Button state detection
- Rising-edge detection (LOW → HIGH)
- Software debouncing
- State machine design
- Non-blocking timing using `millis()`
- Modular code structure

---

## 📂 Projects Completed

### 1️⃣ Button LED Control

A foundational project demonstrating:

- Basic digital input handling
- Pull-down resistor logic
- Direct mapping of input to output
- Simple conditional logic

Behavior:
- Button pressed → LED ON
- Button released → LED OFF

This project establishes the fundamental understanding of input-to-output control systems.

---

### 2️⃣ LED Selector (Mode-Based Controller)

An advanced project building on the first one.

Features:
- Rising-edge detection
- Software debouncing (200 ms)
- Mode cycling logic
- Simple state machine
- Non-blocking blinking using `millis()`

Behavior:
- Mode 0 → OFF
- Mode 1 → ON
- Mode 2 → Slow Blink
- Mode 3 → Fast Blink

This project demonstrates structured embedded system design and real hardware reliability considerations.

---

## 📈 Progression Within the Week

The week intentionally progresses from:

Basic Input →  
Event Detection →  
Debouncing →  
State Management →  
Non-Blocking Scheduling

This evolution reflects a shift from beginner-level Arduino sketches to structured embedded system architecture.

---

## 🧪 Real Hardware Considerations

Unlike simulation environments, physical hardware introduces:

- Mechanical button bounce
- Electrical noise
- Timing instability

Software debouncing and structured logic were necessary to ensure stable real-world behavior.

---

## ✅ Learning Outcome

By the end of Week 2, the following skills were developed:

- Reliable digital input handling
- Practical understanding of pull-down resistors
- Edge detection implementation
- Software-based signal filtering
- State machine construction
- Non-blocking execution design
- Modular embedded architecture

Week 2 represents the transition from simple I/O control to event-driven embedded system design.# Week 2 Projects
