# INSTALLATION MANUAL
## It's important to know!
- This driver is required for systems below MacOS X Mojave 10.14
- It should not be installed out of order
- This driver is needed for copies of Arduino boards with the chip ch340
## Installing
- Disconnect all USB devices and ch340 devices
- Unload the old drivers if running:
	* `sudo kextunload /Library/Extensions/usbserial.kext`
	* `sudo kextunload /System/Library/Extensions/usb.kext`
- Remove the old driver by issuing one of the following commands:
	* `sudo rm -rf /System/Library/Extensions/usb.kext`
	* `sudo rm -rf /Library/Extensions/usbserial.kext`
- Run "Driver.pkg"
- Instead of rebooting, you can force quit Installer after it completes.