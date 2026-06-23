# Temperature and Humidity Logging with Real-Time Data Visualization

This repository contains an end-to-end environmental monitoring system. The project micro-manages data acquisition through embedded firmware and leverages Python scripts to parse, log, and visualize the incoming environmental data into graphical formats.

## 📊 System Architecture & Data Flow
The project is split into two primary layers to demonstrate both low-level hardware control and high-level data processing:
1. **Hardware Layer (Embedded C/C++):** Establishes a stable connection with the DHT sensor, processes physical climate readings, and streams structural data via Serial communication.
2. **Data & Analytics Layer (Python):** Captures the real-time serial stream, logs the data into structured files, and generates visual analytics (plots/graphs) for comprehensive environmental evaluation.

## 🛠️ Technical Specifications
* **Firmware Language:** Embedded C/C++ (Microcontroller Architecture)
* **Data & Analytics Language:** Python (Data Visualization and Processing)
* **Sensor Integration:** Single-bus digital signal processing via DHT11/DHT22.
* **Output & Visualization:** Real-time graphical tracking and local data logging.

## 💡 Engineering & Implementation Details
* **Sensor Calibration:** Firmware utilizes timing intervals to avoid sensor self-heating and ensures high data integrity.
* **Stream Parsing:** The Python layer actively listens to the assigned COM/Serial port, preventing data loss during multi-variable streaming.
* **Graphical Rendering:** Collected data points are mathematically plotted to visually map temperature and humidity trends over time.

## 📁 Project Structure & Assets
*(Coming Soon)* This repository will actively maintain:
* `/src_embedded`: Firmware source files.
* `/src_python`: Python scripts for logging and visualization.
* `/hardware_images`: Physical circuit photos and schematics.
* `/output_plots`: Sample generated graphs and data trends.

## 🚀 Setup & Usage
1. Connect the DHT sensor to the designated digital pin on your microcontroller.
2. Upload the embedded firmware using your standard development environment.
3. Configure and execute the Python visualization script, ensuring the correct Serial port configuration.
4. Monitor live environmental trends via the auto-generated graphical interface.
