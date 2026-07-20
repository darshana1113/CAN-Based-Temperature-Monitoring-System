# CAN-Based-Temperature-Monitoring-System

## 📖 Overview :

This repository contains two embedded systems projects developed using **Arduino Uno**, **ESP8266 NodeMCU**, **MCP2515 CAN Bus modules**, and a **DHT22 Temperature Sensor**. The projects demonstrate the complete development workflow, starting from CAN Bus communication testing and progressing to a temperature monitoring system with an automatic LED warning.

The repository is organized into two independent projects. The first project validates CAN Bus communication between the Arduino Uno and ESP8266, while the second project builds upon that communication by transmitting real-time temperature data from a DHT22 sensor and generating an LED alert when the temperature exceeds a predefined threshold.

---

# 📂 Repository Structure :

```text
Arduino-ESP8266-DHT22-Communication
│
├── Arduino_To_ESP8266_Test
│   ├── Arduino_Code
│   ├── ESP8266_Code
│   ├── Circuit_Diagram
│   ├── Images
│   └── README.md
│
├── Arduino_ESP8266_DHT22
│   ├── Arduino_Code
│   ├── ESP8266_Code
│   ├── Circuit_Diagram
│   ├── Images
│   └── README.md
│
└── README.md
```

---

# 📁 Repository Contents :

## 1️⃣ Arduino_To_ESP8266_Test :

This project demonstrates **CAN Bus communication testing** between an Arduino Uno and an ESP8266 NodeMCU using **two MCP2515 CAN Bus modules**.

The Arduino Uno acts as the CAN transmitter and periodically sends test messages over the CAN Bus. The ESP8266 receives the CAN frames, decodes the transmitted data, and displays the received information on the Serial Monitor.

This project was developed to verify reliable CAN communication before implementing the complete temperature monitoring system.

For implementation details, wiring, source code, and results, refer to:

**`Arduino_To_ESP8266_Test/README.md`**

---

## 2️⃣ Arduino_ESP8266_DHT22 :

This is the main embedded systems project in this repository.

The Arduino Uno interfaces with a DHT22 temperature sensor and transmits temperature data over the CAN Bus using an MCP2515 module. The ESP8266 receives the transmitted data, reconstructs the temperature value, and compares it against a predefined threshold.

Whenever the received temperature reaches or exceeds **30°C**, the ESP8266 activates an LED as an overheat warning. Otherwise, the LED remains OFF while the system continues monitoring the incoming temperature values.

For complete implementation details, hardware connections, circuit diagrams, workflow, and results, refer to:

**`Arduino_ESP8266_DHT22/README.md`**

---

# 🛠 Hardware Used :

* Arduino Uno
* ESP8266 NodeMCU
* MCP2515 CAN Bus Module ×2
* DHT22 Temperature Sensor
* LED
* 220Ω Resistor
* Breadboard
* Jumper Wires
* USB Cables

---

# 💻 Software & Libraries :

### Software

* Arduino IDE

### Libraries

* SPI Library
* MCP_CAN Library
* DHT Library
* ESP8266 Board Package

---

# 🎯 Skills Demonstrated :

* Embedded C/C++ Programming
* Arduino Programming
* ESP8266 Programming
* CAN Bus Communication
* MCP2515 CAN Controller Interfacing
* SPI Communication
* DHT22 Sensor Interfacing
* Real-Time Data Transmission
* Sensor Data Processing
* Threshold-Based Alert System
* Embedded System Design
* Git & GitHub Project Organization

---

# 📸 Repository Contents :

Each project folder contains:

* Source Code
* Circuit Diagram
* Hardware Images
* Project Documentation
* Individual README

---

# 🚀 Future Enhancements :

* Transmit both temperature and humidity values over the CAN Bus.
* Integrate cloud-based data logging.
* Develop a web dashboard for remote monitoring.
* Add OLED/LCD display support.
* Store historical sensor data.
* Expand the system to support multiple CAN nodes.

---

# 👨‍💻 Author :

**Your Name**

Electronics and Communication Engineering Student

GitHub: https://github.com/darshanayadav2005

---

# 📄 License

This project is licensed under the **MIT License**.

You are free to use, modify, and distribute this project for educational and learning purposes with appropriate attribution.
