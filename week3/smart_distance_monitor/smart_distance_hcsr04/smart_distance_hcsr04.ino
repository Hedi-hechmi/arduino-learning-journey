const int trigPin = 9;
const int echoPin = 10;
const int ledPin  = 6;

float minDistance = 5.0;     // closest usable distance (cm)
float maxDistance = 100.0;   // far distance limit (cm)

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