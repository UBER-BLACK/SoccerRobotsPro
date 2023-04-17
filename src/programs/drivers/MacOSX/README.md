# INSTALLATION MANUAL
## It's important to know!
- This driver is required for **systems below MacOS X Mojave 10.14**
- It should not be installed out of order
- This driver is needed for copies of Arduino boards with the **chip ch340**
## Installing
1. Download "**![Driver.pkg](https://github.com/UBER-BLACK/SoccerRobotsPro/raw/main/src/programs/drivers/MacOSX/Driver.pkg)**" (WITHOUT STARTING IT)
1. Disconnect all USB devices and ch340 devices
1. Unload the old drivers if running:
	* `sudo kextunload /Library/Extensions/usbserial.kext`
	* `sudo kextunload /System/Library/Extensions/usb.kext`
1. Remove the old driver by issuing one of the following commands:
	* `sudo rm -rf /System/Library/Extensions/usb.kext`
	* `sudo rm -rf /Library/Extensions/usbserial.kext`
1. Run "**![Driver.pkg](https://github.com/UBER-BLACK/SoccerRobotsPro/raw/main/src/programs/drivers/MacOSX/Driver.pkg)**"
1. Instead of rebooting, you can force quit Installer after it completes.



Driver by ![adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver](https://github.com/adrianmihalko/ch340g-ch34g-ch34x-mac-os-x-driver)
Thank you ![@adrianmihalko](https://github.com/adrianmihalko)
