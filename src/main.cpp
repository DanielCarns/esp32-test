#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEScan.h>
#include <BLEAdvertisedDevice.h>
 
class DeviceCallbacks: public BLEAdvertisedDeviceCallbacks {
	void onResult(BLEAdvertisedDevice advertisedDevice) {
		ESP_LOGD(LOG_TAG, "Advertised Device: %s", advertisedDevice.toString().c_str());
	}
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Scanning...");

  BLEDevice::init("theDashBoard");
  BLEScan* pBLEScan = BLEDevice::getScan();
  pBLEScan->setAdvertisedDeviceCallbacks(new DeviceCallbacks());
  pBLEScan->setActiveScan(true);
  BLEScanResults foundDevices = pBLEScan->start(30);
  Serial.println("Scan done!");
}

void loop() {}
