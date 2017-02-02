#include "CurieIMU.h"


void setup() {

  Serial.begin(9600);

  // Initialize internal IMU
  CurieIMU.begin();

  // Set accelerometer range to 2G
  CurieIMU.setAccelerometerRange(2);
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
  delay(100);
}
