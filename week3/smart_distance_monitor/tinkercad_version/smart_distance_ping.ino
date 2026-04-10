const int pingPin = 9;
const int ledPin  = 6;

float minDistance = 5.0;    // cm
float maxDistance = 100.0;  // cm

void setup() {
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  float distance = readDistance();
  int brightness = calculateBrightness(distance);

  updateLed(brightness);

  delay(100);
}

// ----------------------------
// Function: Read Distance
// ----------------------------
float readDistance() {

  long duration;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);

  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  float distance = duration * 0.0343 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  return distance;
}

// ----------------------------
// Function: Calculate Brightness
// ----------------------------
int calculateBrightness(float distance) {

  int brightness = map(distance, minDistance, maxDistance, 255, 0);
  brightness = constrain(brightness, 0, 255);

  return brightness;
}

// ----------------------------
// Function: Update LED
// ----------------------------
void updateLed(int brightness) {
  analogWrite(ledPin, brightness);
}