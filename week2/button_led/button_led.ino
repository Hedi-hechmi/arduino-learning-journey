const int buttonPin = 2;
const int ledPin = 8;

int lastMode = -1;
int currentState = LOW;
int lastState = LOW;
int mode = 0;
unsigned long previousMillis = 0;
unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;
bool ledState = LOW;

int lastReading = LOW;

void setup() {
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {

  int reading = digitalRead(buttonPin);

  if (reading != lastReading) {
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {

    if (reading != currentState) {
      currentState = reading;

      if (currentState == HIGH) {
        mode++;

        if (mode > 3) {
          mode = 0;
        }

        Serial.println(mode);
      }
    }
  }

  lastReading = reading;
  handleLedMode();
}
void handleLedMode(){
  if (mode != lastMode) {
    previousMillis = millis();
    ledState = LOW;
    digitalWrite(ledPin, LOW);
    lastMode = mode ;
      }
  switch (mode) {
    case 0:
    	digitalWrite(ledPin, LOW);
    	break;
    case 1:
    	digitalWrite(ledPin, HIGH);
    	break;
    case 2:
    	blinkLed(1000);
    	break;
    case 3:
    	blinkLed(200);
    	break;
    }
  }
void blinkLed(unsigned long interval) {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    ledState = !ledState;
    digitalWrite(ledPin, ledState);
    }
  }
    