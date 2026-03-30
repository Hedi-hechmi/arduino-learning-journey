const int buttonPin = 2;
const int ledPin = 8;

int mode = 0;

bool buttonState = LOW;
bool lastButtonState = LOW;

unsigned long lastPressTime = 0;
const unsigned long debounceTime = 200;   // stronger debounce

unsigned long previousMillis = 0;
bool ledState = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  buttonState = digitalRead(buttonPin);

  // Detect press (rising edge)
  if (buttonState == HIGH && lastButtonState == LOW) {

    if (millis() - lastPressTime > debounceTime) {
      mode++;
      if (mode > 3) mode = 0;

      Serial.println(mode);
      lastPressTime = millis();
    }
  }

  lastButtonState = buttonState;

  handleMode();
}

void handleMode() {

  switch (mode) {

    case 0:
      digitalWrite(ledPin, LOW);
      break;

    case 1:
      digitalWrite(ledPin, HIGH);
      break;

    case 2:
      blink(1000);
      break;

    case 3:
      blink(200);
      break;
  }
}

void blink(unsigned long interval) {

  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
  }
}