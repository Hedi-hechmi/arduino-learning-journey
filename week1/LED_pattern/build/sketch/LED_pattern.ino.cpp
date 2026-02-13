#include <Arduino.h>
#line 1 "C:\\Users\\Hedi\\arduino-learning-journey\\week1\\LED_\\LED_pattern\\LED_pattern.ino"
const int Ledpin = 8; // LED connected to digital pin 8
#line 2 "C:\\Users\\Hedi\\arduino-learning-journey\\week1\\LED_\\LED_pattern\\LED_pattern.ino"
void setup();
#line 6 "C:\\Users\\Hedi\\arduino-learning-journey\\week1\\LED_\\LED_pattern\\LED_pattern.ino"
void loop();
#line 15 "C:\\Users\\Hedi\\arduino-learning-journey\\week1\\LED_\\LED_pattern\\LED_pattern.ino"
void Blinkonce(int duration);
#line 22 "C:\\Users\\Hedi\\arduino-learning-journey\\week1\\LED_\\LED_pattern\\LED_pattern.ino"
void flash3times(int duration);
#line 32 "C:\\Users\\Hedi\\arduino-learning-journey\\week1\\LED_\\LED_pattern\\LED_pattern.ino"
void LongOne(int duration);
#line 2 "C:\\Users\\Hedi\\arduino-learning-journey\\week1\\LED_\\LED_pattern\\LED_pattern.ino"
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
