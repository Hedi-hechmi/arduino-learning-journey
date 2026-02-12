// Blink the Arduino built‑in LED with a delay of 2 seconds

void setup()
{
    pinMode(LED_BUILTIN, OUTPUT); // configure LED pin as output
}

void loop()
{
    digitalWrite(LED_BUILTIN, HIGH); // turn LED on
    delay(2000);                     // wait 2 seconds
    digitalWrite(LED_BUILTIN, LOW);  // turn LED off
    delay(2000);                     // wait 2 seconds
}