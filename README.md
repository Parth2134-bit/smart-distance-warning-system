# Smart Distance Warning System

An Arduino Uno-based distance monitoring and warning system built using an HC-SR04 ultrasonic sensor, three LEDs, a buzzer, and a 16×2 I²C LCD. The project measures the distance to an object and provides visual and audible warnings based on proximity.

## Features

- Real-time distance measurement using an ultrasonic sensor
- LCD display showing distance and warning status
- Three-level visual indication using green, yellow, and red LEDs
- Audible alerts using a buzzer
- Serial Monitor output for debugging
- Timeout handling for missing ultrasonic echoes

## Components Used

- Arduino Uno
- HC-SR04 ultrasonic sensor
- 16×2 LCD with I²C interface
- Green, yellow, and red LEDs
- 220 Ω resistors
- Buzzer
- Wokwi simulator

## Pin Connections

| Component | Arduino Uno pin |
|---|---|
| Ultrasonic TRIG | D3 |
| Ultrasonic ECHO | D2 |
| Green LED | D4 |
| Yellow LED | D5 |
| Red LED | D6 |
| Buzzer | D7 |
| LCD SDA | A4 |
| LCD SCL | A5 |
| LCD VCC | 5V |
| LCD GND | GND |

## Operating Logic

| Distance | LED | Status |
|---|---|---|
| Greater than 30 cm | Green | SAFE |
| Greater than 10 cm and up to 30 cm | Yellow | WARNING |
| 10 cm or less | Red | DANGER |

If no ultrasonic echo is detected, the LEDs and buzzer are turned off and the LCD displays an error status.

## Run the Project

1. Open the Wokwi simulation using the project link in `wokwi-project.txt`.
2. Ensure the `LiquidCrystal I2C` library is available.
3. Start the simulation.
4. Change the simulated object distance and observe the LCD, LEDs, and buzzer.

## Project Files

- `sketch.ino` — Arduino source code
- `diagram.json` — Circuit layout and connections
- `libraries.txt` — Required Wokwi library
- `wokwi-project.txt` — Simulation link

## Future Improvements

- Filter noisy sensor readings
- Adjust buzzer beep frequency based on distance
- Add a mute button
- Validate the design using physical hardware

## Contributors

- Parth Khatri
- Akshansh Sharma

## Development Environment

Arduino C++ · Arduino Uno · Wokwi Simulator

*This project was developed and simulated in Wokwi. Physical hardware testing should be documented separately if performed.*
