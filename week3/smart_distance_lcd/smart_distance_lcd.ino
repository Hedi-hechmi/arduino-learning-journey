#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Try 0x27 first. If nothing shows, change to 0x3F.
LiquidCrystal_I2C lcd(0x27, 16, 2);

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

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Distance System");
  delay(1500);
  lcd.clear();
}

void loop() {

  float distance = readDistance();
  int brightness = calculateBrightness(distance);
  String status = getStatus(distance);

  analogWrite(ledPin, brightness);
  updateLCD(distance, status);

  delay(200);
}

// =========================
// Read Distance (HC-SR04)
// =========================
float readDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // 30ms timeout prevents blocking if no echo
  long duration = pulseIn(echoPin, HIGH, 30000);

  if (duration == 0) {
    return 0;  // No echo detected
  }

  float distance = duration * 0.0343 / 2;

  return distance;
}

// =========================
// Convert Distance → LED
// =========================
int calculateBrightness(float distance) {

  if (distance == 0) return 0;

  int brightness = map(distance, minDistance, maxDistance, 255, 0);
  brightness = constrain(brightness, 0, 255);

  return brightness;
}

// =========================
// Determine Status
// =========================
String getStatus(float distance) {

  if (distance == 0) return "NO SIGNAL";

  if (distance < 20) {
    return "CLOSE";
  }
  else if (distance < 60) {
    return "MEDIUM";
  }
  else {
    return "FAR";
  }
}

// =========================
// Update LCD
// =========================
void updateLCD(float distance, String status) {

  lcd.clear();

  lcd.setCursor(0, 0);
  lcd.print("Dist: ");

  if (distance == 0) {
    lcd.print("--.- cm");
  } else {
    lcd.print(distance, 1);
    lcd.print(" cm");
  }

  lcd.setCursor(0, 1);
  lcd.print("Status: ");
  lcd.print(status);
}