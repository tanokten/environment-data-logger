# Temperature and Humidity Logging with Real-Time Data Visualization

This repository contains an end-to-end environmental monitoring system. The project manages real-time data acquisition through embedded firmware and leverages a Python script to parse, log, and visualize the incoming climate data into dynamic graphical formats.

## 📊 System Architecture & Data Flow
The project demonstrates both low-level hardware control and high-level data processing:
1. **Hardware Layer (Embedded C/C++):** Establishes a stable digital connection with the DHT sensor, processes physical climate readings, and streams structured data via Serial communication.
2. **Data & Analytics Layer (Python):** Captures the real-time serial stream, logs the data locally, and generates visual plots for comprehensive environmental evaluation.

## 📷 Hardware Setup
Below is the physical implementation and circuit design of the project:

<img src="FOTOGRAFIN_ADI.jpg" width="500" alt="Hardware Setup">

## 📈 Data Visualization Output
The Python script processes the collected data points and generates the following graphical analysis mapping temperature and humidity trends over time:

<img src="GRAFIGIN_ADI.png" width="600" alt="Data Visualization Plot">

## 🛠️ Technical Specifications
* **Firmware Language:** Embedded C/C++ (Microcontroller Architecture)
* **Data & Analytics Language:** Python (Data Visualization and Processing)
* **Sensor Integration:** Single-bus digital signal processing via DHT11/DHT22.

## 🚀 Setup & Usage
1. Connect the DHT sensor to the designated digital pin on your microcontroller.
2. Upload the embedded firmware code to your hardware.
3. Configure and execute the Python visualization script, ensuring the correct Serial port (COM port) configuration.
4. Monitor live environmental trends via the auto-generated graphical interface.
