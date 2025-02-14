# Arduino Blinds Controller

This project automates the opening and closing of window blinds using an Arduino-controlled motor driver. The blinds adjust direction at a specified interval (default: 12 hours) using an H-bridge motor driver.

## Features

- Automatic blinds control with adjustable time intervals
- Uses an H-bridge motor driver for bidirectional motor control
- Simple and efficient implementation using Arduino

## Hardware Requirements

- **Arduino Board** (e.g., Arduino Uno)
- **H-Bridge Motor Driver** (L298N or similar)
- **DC Motor** (compatible with the blinds mechanism)
- **Power Supply** (suitable for the motor and Arduino)
- **Wiring and Connectors**

## Wiring Diagram

| Arduino Pin | Motor Driver Pin | Description |
|-------------|----------------|-------------|
| **3 (PWM)** | **Enable (ENA/ENB)** | Speed control |
| **12** | **IN1** | Motor direction control |
| **11** | **IN2** | Motor direction control |

## Images
![alt text](arduinoBlindsImg.png "Title")

![alt text](IRL_Img.png)
