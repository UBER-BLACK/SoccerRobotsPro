[![ENGLISH SHIELD](https://img.shields.io/badge/-English-444?style=flat-square)]()
[![RUSSIAN SHIELD](https://img.shields.io/badge/-Русский-08f?style=flat-square)](RU_README.md)
[![DOWNLOAD SHIELD](https://img.shields.io/badge/-Скачать-F00?style=flat-square)](https://github.com/UBER-BLACK/SoccerRobotsPro/raw/main/src/software/driver/macos/driver.pkg)
# ИНСТРУКЦИЯ ПО УСТАНОВКЕ
## Вам нужно занать!
- Этот драйвер нужен для **систем ниже MacOS Mojave 10.14**
- Не следует устанавливать его не по порядку
- Этот драйвер необходим для прошивки копий плат Arduino с **чипом ch340**
## Установка
1. Скачайте "**![driver.pkg](https://github.com/UBER-BLACK/SoccerRobotsPro/raw/main/src/software/driver/macos/driver.pkg)**" (НЕ ЗАПУСКАЯ ЕГО)
1. Отключите все USB и ch340 устройства 
1. Выгрузите старые драйверы:
	* `sudo kextunload /Library/Extensions/usbserial.kext`
	* `sudo kextunload /System/Library/Extensions/usb.kext`
1. Удалите старый драйвер:
	* `sudo rm -rf /System/Library/Extensions/usb.kext`
	* `sudo rm -rf /Library/Extensions/usbserial.kext`
1. Запустите "**![driver.pkg](https://github.com/UBER-BLACK/SoccerRobotsPro/raw/main/src/software/driver/macos/driver.pkg)**"
1. Вместо перезагрузки вы можете принудительно выйти из программы установки после ее завершения.



Драйвер взят из ![adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver)

**Спасибо тебе ![@adrianmihalko](https://github.com/adrianmihalko)**
