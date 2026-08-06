Smart Bio Pulse Oximetry Monitor 

About The Project:
A smart medical device simulator designed to monitor blood oxygen levels (SpO2) and heart rate (BPM) using Arduino, an LCD screen, a potentiometer for biosignal simulation, LEDs, and a buzzer for real-time risk alerts.

How It Works
The Arduino reads the potentiometer value to simulate real-time human pulse and oxygen signals:

Signal Processing: Converts the analog reading from the potentiometer into SpO2 percentage and BPM values, displaying them on the LCD screen.

Normal State: If oxygen levels are safe, the green LED turns ON, and a soft periodic pulse tone plays.

Danger State: If oxygen levels drop below 92%, the red LED turns ON, green LED turns OFF, and a continuous high-pitch alarm is triggered.

Components Used
Arduino Uno

LiquidCrystal I2C LCD (16x2)

Potentiometer

Green LED

Red LED

Buzzer

Connecting Wires

Circuit Diagram and Simulation
Tinkercad Simulation Link:
https://www.tinkercad.com/things/f00Mukzcf00-smart-bio-pluse-amp-oximetry-monitor

Project Files
Arduino Source Code: Smart Bio Pulse Oximetry Monitor.ino

Project Documentation: Smart Bio Pulse Oximetry Monitor.pdf
