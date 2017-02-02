#include "CurieIMU.h"
#include "CurieBLE.h"

BLEPeripheral blePeripheral;
BLEService IMUService("A8DD0000-0574-48DD-B570-21B2DB19807E"); // BLE Unique Service
BLEFloatCharacteristic IMUAXChar("A8DD0001-0574-48DD-B570-21B2DB19807E", BLERead | BLENotify);
BLEFloatCharacteristic IMUAYChar("A8DD0002-0574-48DD-B570-21B2DB19807E", BLERead | BLENotify);
BLEFloatCharacteristic IMUAZChar("A8DD0003-0574-48DD-B570-21B2DB19807E", BLERead | BLENotify);

void setup() {

  Serial.begin(9600);

  // Initialize internal IMU
  CurieIMU.begin();

  // Set accelerometer range to 2G
  CurieIMU.setAccelerometerRange(2);

  // Setting for BLE device
  blePeripheral.setLocalName("IMUTestSketch");
  blePeripheral.setAdvertisedServiceUuid(IMUService.uuid());
  blePeripheral.addAttribute(IMUService);
  blePeripheral.addAttribute(IMUAXChar);
  blePeripheral.addAttribute(IMUAYChar);
  blePeripheral.addAttribute(IMUAZChar);
  IMUAXChar.setValue(0);
  IMUAYChar.setValue(0);
  IMUAZChar.setValue(0);

  blePeripheral.begin();
}

void loop() {
  float ax, ay, az;

  CurieIMU.readAccelerometerScaled(ax, ay, az);
  Serial.print("Value ax:");
  Serial.print(ax);
  Serial.print(" / ay:");
  Serial.print(ay);
  Serial.print(" / az:");
  Serial.println(az);

  IMUAXChar.setValue(ax);
  IMUAYChar.setValue(ay);
  IMUAZChar.setValue(az);

  delay(10);
}
