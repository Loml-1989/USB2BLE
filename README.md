# USB2BLE
USB2BLE is a project designed to convert a USB controller into a Bluetooth gamepad.
It uses a Seeed Studio XIAO ESP32 S3 acting as a USB Host to read the USB.
## Features
- **USB Host to Bluetooth Translation:** Intercepts raw USB HID data from a controller and broadcasts it as a standard Bluetooth gamepad to PCs and mobile devices.
- **Integrated Power:** MT3608 steps up the 3.7V LiPo battery to the 5V (required by the USB).
## Enclosure
Assembly hardware requires M2 x 8mm Socket Head Cap screws. The space under the PBC is meant to for the flat LiPo battery pack.
## Firmware Setup
Because the ESP32 S3 must act as a USB host, this project relies on the native ESP32 TinyUSB stack. Currently the firmware DOES NOT work to translate the controller's inputs. The current firmware prints the output data when a button is pressed the reason is that every controller has different mappings so first we need to find that mapping then map it in the firmware only then it will work.
### Required Library:
- [ESP32-BLE-Gamepad](https://github.com/lemmingDev/ESP32-BLE-Gamepad "null") (by lemmingDev)