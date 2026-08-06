#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

const int potPin = A0;
const int greenLed = 2;
const int redLed = 3;
const int buzzer = 4;

unsigned long previousMillis = 0;
const long interval = 500;

void setup()
{
    pinMode(greenLed, OUTPUT);
    pinMode(redLed, OUTPUT);
    pinMode(buzzer, OUTPUT);

    lcd.init();
    lcd.backlight();

    lcd.setCursor(0, 0);
    lcd.print("Pulse Oximeter");
    lcd.setCursor(0, 1);
    lcd.print("Initializing...");
    delay(2000);
    lcd.clear();
}

void loop()
{
    unsigned long currentMillis = millis();

    if (currentMillis - previousMillis >= interval)
    {
        previousMillis = currentMillis;

        int rawValue = analogRead(potPin);

        int spo2 = map(rawValue, 0, 1023, 100, 75);
        int bpm = map(rawValue, 0, 1023, 110, 60) + random(-2, 3);

        lcd.setCursor(0, 0);
        lcd.print("SpO2: ");
        if (spo2 < 100)
            lcd.print(" ");
        lcd.print(spo2);
        lcd.print("%   ");

        lcd.setCursor(0, 1);
        lcd.print("BPM : ");
        if (bpm < 100)
            lcd.print(" ");
        lcd.print(bpm);
        lcd.print("     ");

        if (spo2 < 92)
        {
            digitalWrite(redLed, HIGH);
            digitalWrite(greenLed, LOW);

            tone(buzzer, 1000);
        }
        else
        {
            digitalWrite(redLed, LOW);
            digitalWrite(greenLed, HIGH);
            noTone(buzzer);

            // صوت نبضة خفيف
            tone(buzzer, 800, 50);
        }
    }
}