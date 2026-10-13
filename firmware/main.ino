#include <Arduino.h>
#include <BleGamepad.h>
#include <USB.h>
#include <USBHost.h>
#include <class/hid/hid_host.h>

BleGamepad bleGamepad("Cosmic Bridge", "P. Diddy", 100);

void setup() {
  Serial.begin(115200);
  Serial.println("Starting bluetooth gamepad.");
  bleGamepad.begin();

  USBHost.begin();
  Serial.println("USB Host initialized and now I am waiting for controller");
}

void loop() {
  delay(10);
}

extern "C" {
  void tuh_hid_mount_cb(uint8_t dev_addr, uint8_t instance, uint8_t const* desc_repo, uint16_t desc_len) {
    Serial.println("Device connected and the address is: ");
    Serial.println(dev_addr);
    tuh_hid_receive_report(dev_addr, instance);
  }

  void tuh_hid_umount_cb(uint8_t dev_addr, uint8_t instance) {
    for(uint16_t i=0; i < len; i++) {
      if (report[i] < 16) {
        Serial.println("0");
      }
      Serial.print(report[i], HEX);
      serial.print(" ");
    }
    Serial.print();
    
    tuh_hid_receive_report(dev_addr, instance);
  }
}
