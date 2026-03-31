const int ldrPin = A0;
const int ledPin = 9;

const int minLight = 12;     // measured dark value
const int maxLight = 1004;   // measured bright value

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