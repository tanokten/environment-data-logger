# Temperature and Humidity Logging System

This repository contains the embedded software designed for an environmental monitoring system. The core objective of the project is to establish a stable digital connection with a DHT sensor, process ambient climate data in real-time, and log the outputs effectively.

## 📊 System Overview
The architecture relies on a standard microcontroller retrieving physical data from an ambient sensor. Instead of continuous unstructured reading, the firmware manages timing and intervals to ensure precise data acquisition and minimal sensor heating issues.

## 🛠️ Project Specifications
* **Architecture:** Embedded C/C++ (Microcontroller Firmware)
* **Sensor Integration:** Single-bus digital signal processing via DHT sensor.
* **Output Medium:** Serial data stream for logging and monitoring.

## 💡 Engineering & Implementation Details
The codebase is structured to handle basic embedded protocols and data streams:
1. **Sensor Initialization:** Verifies the hardware connection on boot.
2. **Data Acquisition:** Reads the relative humidity and Celsius temperature signals using precise timing intervals.
3. **Data Integrity:** Implements check procedures to prevent incorrect or corrupted readings from entering the main system loop.
4. **Output Logging:** Formats the verified data and transmits it to the host computer for real-time tracking.

## 🚀 Setup & Usage
1. Connect the DHT sensor's data pin to the specified digital pin on your microcontroller board.
2. Provide appropriate power (VCC and GND) according to your specific hardware setup.
3. Upload the source code using your standard embedded development environment (IDE).
4. Open the serial terminal to monitor the continuous live environment logs.
