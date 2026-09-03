Modular Vehicle Monitoring System | ESP32

An ESP32-based embedded monitoring system developed to explore real-time vehicle sensor acquisition and onboard data logging for motorsport-inspired applications.

Overview

The system collects environmental sensor data using an ESP32 microcontroller and provides real-time feedback through an OLED display. Sensor data can also be stored locally in the ESP32’s onboard flash memory as a CSV file for offline analysis.

The project is being developed as a modular platform, allowing additional vehicle parameters and sensors to be integrated in future iterations.

Current Features

* Real-time temperature and humidity sensing using a DHT11
* OLED-based sensor data display
* ESP32 embedded firmware developed using Arduino IDE
* Local data logging using LittleFS flash storage
* CSV-formatted sensor data
* Flash data retrieval through serial communication
* Modular firmware structure for future sensor integration

System Architecture

        DHT11 Sensor
             │
             │ Digital Data
             ▼
          ESP32
        ┌────┴─────┐
        │          │
        ▼          ▼
      OLED       LittleFS
     Display      Flash
                   │
                   ▼
              CSV Dataset
                   │
                   ▼
              Offline Analysis

Hardware

* ESP32 development board
* DHT11 temperature and humidity sensor
* 0.96” I2C OLED display
* Breadboard and jumper wires

Software

* Arduino IDE
* C++
* ESP32 Arduino Core
* LittleFS
* DHT sensor library
* Adafruit GFX / SSD1306 libraries

Data Logging

Sensor data is periodically sampled and appended to a CSV file stored in the ESP32’s onboard flash memory.

Example:

Time(s),Temperature(C),Humidity(%)
0,26.0,58.0
2,26.0,58.0
4,27.0,57.0
6,27.0,57.0

The recorded data can be retrieved from the ESP32 through the serial interface and subsequently analysed offline.

Development Progress

Completed

* [x]	ESP32 development environment setup
* [x]	OLED I2C communication
* [x]	Digital temperature sensor acquisition
* [x]	Real-time sensor display
* [x]	LittleFS flash storage
* [x]	CSV data logging
* [x]	Flash data retrieval

Future Development

* [ ]	Integration of the vehicle’s LM35 temperature sensor
* [ ]	Improved data logging and file management
* [ ]	Python-based CSV analysis and temperature-time plotting
* [ ]	Integration of additional vehicle parameters where hardware is available

Motivation

The project was developed to gain practical experience in embedded systems and to investigate how vehicle sensor data can be collected, stored and analysed during operation.

The longer-term goal is to develop the system into a more representative vehicle telemetry platform while keeping the firmware modular and extensible.

Author

Electrical and Electronic Engineering student at the University of Bristol.
