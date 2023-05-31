[![ENGLISH SHIELD](https://img.shields.io/badge/-English-08f?style=flat-square)]()
[![RUSSIAN SHIELD](https://img.shields.io/badge/-Русский-444?style=flat-square)](RU_README.md)
[![DOWNLOAD SHIELD](https://img.shields.io/badge/-Download-F00?style=flat-square)](https://github.com/UBER-BLACK/SoccerRobotsPro/raw/main/src/software/firmware/firmware.ino)
# Robot Firmware
This firmware is made for our soccer robot

# Installing

1. Download "**![firmware.ino](https://github.com/UBER-BLACK/SoccerRobotsPro/raw/main/src/software/firmware/firmware.ino)**"
1. Open this file in the "**[![Arduino IDE]()](https://www.arduino.cc/en/software)**"
1. Install all **![libraries](https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/libraries)** in the IDE
1. Install the **![driver](https://github.com/UBER-BLACK/SoccerRobotsPro/tree/main/src/software/driver)** for the Arduino with **chip ch340**
1. Specify the board and port
1. Press the flash button

# Customizing

Open the file in "**[![Arduino IDE]()](https://www.arduino.cc/en/software)**" and find the settings part (very easy to find)
```C++
#define Name Value //URL to the guide
```

## Monitor

### Monitor_Speed

  - May have a value of: **``...9600, 19200, 31250, 38400, 57600, 74880, 115200, 230400, 250000, 460800, 500000...``**
  - Recommended: **``9600``**
  - This parameter is responsible for the speed of USB data exchange with the computer (don't forget to change this parameter in the port monitor)

### (Name)_Monitor

  - May have a value of: **``false``** or **``true``**
  - Recommended: **``false``**
  - This parameter is responsible for turning on this monitor

### (Name)_MonitorDelay

  - May have a value of: **``0 - 5000``**
  - Recommended: **``2000``**
  - This parameter is responsible for the monitor output delay in ms

## Gearbox

### Gearbox_MaxSpeed

  - May have a value of: **``0.1 - 1.0``**
  - Recommended: **``0.9``**
  - This parameter is responsible for the division factor in the last gear

### Gearbox_MinSpeed

  - May have a value of: **``0.1 - 1.0``**
  - Recommended: **``0.4``**
  - This parameter is responsible for the division ratio in the first gear

### Gearbox_MinPower

  - May have a value of: **``0 - 255``**
  - Recommended: **``20``**
  - This parameter is responsible for the minimum speed of the motor

### Gearbox_DefGear

  - May have a value of: **``0 - 255``** and <= **![Gearbox_MaxGear](README.md#Gearbox_MaxGear)**
  - Recommended: **``0``**
  - This parameter is responsible for the default transmission (this transmission will be when the robot is turned on)

### Gearbox_MaxGear

  - May have a value of: **``2 - 255``**
  - Recommended: **``2``**
  - This parameter is responsible for the maximum number of gears

### Gearbox_AutoBrake

  - May have a value of: **``false``** or **``true``**
  - Recommended: **``true``**
  - This parameter is responsible for automatic engine braking

### Gearbox_Delay

  - May have a value of: **``0 - 1000``**
  - Recommended: **``250``**
  - This parameter is responsible for the delay of gear shift requests

## Motor

### Motor(Side)_Reverse

  - May have a value of: **``false``** or **``true``**
  - Recommended: **``false``**
  - This parameter is responsible for inverting the direction of motor movement

## Shockpanel

### Shockpanel_MinigunDelay

  - May have a value of: **``0 - 255``**
  - Recommended: **``20``**
  - This parameter is responsible for the rate of fire in minigun mode

### Shockpanel_ShotSpeed

  - May have a value of: **``0 - 255``**
  - Recommended: **``255``**
  - This parameter is responsible for the speed at which the roller will be pushed back on impact

### Shockpanel_HoldSpeed

  - May have a value of: **``0 - 255``**
  - Recommended: **``255``**
  - This parameter is responsible for the speed at which the roller will be sucked in when held down

### Shockpanel_NormSpeed

  - May have a value of: **``0 - 255``**
  - Recommended: **``50``**
  - This parameter is responsible for the speed at which the roller will suck when idle

### Shockpanel_APIBoost

  - May have a value of: **``0.1 - 1.0``**
  - Recommended: **``0.5``**
  - This parameter is responsible for increasing the effect of the underbelly from the API (when moving forward the roller will push, and if backward it will suck)

## Motion

### Motion_ControlSens

  - May have a value of: **``0.1 - 1.0``**
  - Recommended: **``0.4``**
  - This parameter is responsible for the overall sensitivity when turning
