Remote Sensing Blind Cane

An Arduino-based smart assistant project (smart blind stick) that uses an ultrasonic sensor to detect obstacles and provide distance-mapped audio alerts through a buzzer.

---

 🛠️ Components

Arduino UNO

HC-SR04 Ultrasonic Sensor

 Buzzer

Jumper Wires

---

🔌 Pin Connections

HC-SR04 Ultrasonic Sensor:
 `TRIG` pin connected to Digital Pin 9


 `ECHO` pin connected to Digital Pin 8


 `VCC` and `GND` connected to 5V and GND rails


Buzzer:
 Positive terminal connected to Digital Pin 10


 Negative terminal connected to GND





---

 🔗 Tinkercad Simulation

👉 [View Circuit on Tinkercad] (https://www.tinkercad.com/things/f00Mukzcf00-smart-bio-pluse-amp-oximetry-monitor)

---

 💻 Source Code

```cpp
const int trigPin = 9;
const int echoPin = 8;
const int buzzerPin = 10;

long duration;
int distance;

const int dangerZone = 30;
const int warningZone = 100;

void setup()
{
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    Serial.begin(9600);
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH, 30000);

    if (duration == 0)
    {
        distance = warningZone + 1;
    }
    else
    {
        distance = duration * 0.034 / 2;
    }

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance <= dangerZone && distance > 0)
    {
        tone(buzzerPin, 1000);
        delay(50);
    }
    else if (distance > dangerZone && distance <= warningZone)
    {
        int delayTime = map(distance, dangerZone, warningZone, 50, 400);

        tone(buzzerPin, 1000);
        delay(50);
        noTone(buzzerPin);
        delay(delayTime);
    }
    else
    {
        noTone(buzzerPin);
        delay(50);
    }
}
