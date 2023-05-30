[![ENGLISH SHIELD](https://img.shields.io/badge/-English-08f?style=flat-square)]()
[![RUSSIAN SHIELD](https://img.shields.io/badge/-Русский-444?style=flat-square)](RU_README.md)

# Robot Firmware

This firmware is made for our soccer robot

# Installing

1. Download "**![RobotFirmware.ino](https://raw.githubusercontent.com/UBER-BLACK/SoccerRobotsPro/main/src/programs/code/RobotFirmware/RobotFirmware.ino)**"
1. Open this file in the "**[![Arduino IDE]()](https://www.arduino.cc/en/software)**"
1. Install all **![libraries](https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/programs/libraries)** in the IDE
1. Install the **![driver](https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/programs/drivers/ch340)** for the Arduino with **chip ch340**
1. Specify the board and port
1. Press the flash button

# Customizing

Open the file in "**[![Arduino IDE]()](https://www.arduino.cc/en/software)**" and find the settings part (very easy to find)
```C++
#define Name Value //URL to the guide
```

## Monitors

### Monitor Speed

  - May have a value of: **``...9600, 19200, 31250, 38400, 57600, 74880, 115200, 230400, 250000, 460800, 500000...``**
  - Default: **``9600``**
  - This parameter is responsible for the speed of USB data exchange with the computer (don't forget to change this parameter in the port monitor)

### Gamepad_Monitor

  - May have a value of: **``false``** or **``true``**
  - Default: **``false``**
  - This parameter is responsible for the monitor output delay
