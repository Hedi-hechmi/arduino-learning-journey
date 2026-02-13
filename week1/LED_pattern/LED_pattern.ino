const int Ledpin = 8; // LED connected to digital pin 8
void setup()
{
    pinMode(Ledpin, OUTPUT); // Set the LED pin as an output
}
void loop()
{
    Blinkonce(1000); // Blink the LED once with a delay of 1000 milliseconds (1 second)

    flash3times(200); // Flash the LED 3 times with a delay of 200 milliseconds between each flash

    LongOne(3000);
}

void Blinkonce(int duration) // Keep the LED on for 3000 milliseconds (3 seconds)
{
    digitalWrite(Ledpin, HIGH); // Turn the LED on
    delay(duration);
    digitalWrite(Ledpin, LOW); // Turn the LED off
    delay(duration);
}
void flash3times(int duration) // Flash the LED 3 times with a delay of 200 milliseconds between each flash
{
    for (int i = 0; i < 3; i++)
    {
        digitalWrite(Ledpin, HIGH); // Turn the LED on
        delay(duration);
        digitalWrite(Ledpin, LOW); // Turn the LED off
        delay(duration);
    }
}
void LongOne(int duration) // Keep the LED on for 3000 milliseconds (3 seconds)
{
    digitalWrite(Ledpin, HIGH); // Turn the LED on
    delay(duration);
    digitalWrite(Ledpin, LOW); // Turn the LED off
    delay(3000);
}