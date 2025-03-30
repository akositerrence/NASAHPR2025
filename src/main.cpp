#include <Arduino.h>
#include <SPI.h>
#include <prm_imu.h>

// PIN ASSIGNMENTS
const int primaryIMUSlaveSelectPin = 10;

void setup() {

  // SERIAL COMMUNICATION INITIALIZATION 
  Serial.begin(9600);
  while (!Serial) { ; } 

  // INITIALIZE SPI PROTOCOL
  SPI.begin();

  // PIN MODES
  pinMode(primaryIMUSlaveSelectPin, OUTPUT);

  // SENSOR INITIALIZATION 
  prmIMUInitialize(primaryIMUSlaveSelectPin);

  Serial.println("Setup Complete");

}

void loop() {

  // ICM20948 OUTPUTS
  prmIMUData icm20948 = readPrmIMUData();
  Serial.print("ICM20948Accel : ");
  Serial.print(icm20948.acceleration[0]);
  Serial.print(" ");
  Serial.print(icm20948.acceleration[1]);
  Serial.print(" ");
  Serial.println(icm20948.acceleration[2]);

  delay(10);

}