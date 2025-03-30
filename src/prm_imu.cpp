#include <prm_imu.h>
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>

Adafruit_ICM20948 imu;  // CREATE SENSOR OBJECT
int primaryIMUSlaveSelectPin;   // GLOBAL SELECT PIN

void prmIMUInitialize(int selectPin) {

    primaryIMUSlaveSelectPin = selectPin;   // RECEIVE SELECT PIN
    digitalWrite(primaryIMUSlaveSelectPin, HIGH);

    // SPI SANITY CHECK
    Serial.println("Attempting ICM20948 SPI initialization...");
    if (!imu.begin_SPI(primaryIMUSlaveSelectPin)) {
      Serial.println("Failed to initialize ICM20948 via SPI");
      while (1) { delay(10); }
    }
    Serial.println("ICM20948 SPI initialization successful");

    // SET ICM20948 RANGES
    imu.setAccelRange(ICM20948_ACCEL_RANGE_16_G);
    imu.setGyroRange(ICM20948_GYRO_RANGE_1000_DPS);

}

prmIMUData readPrmIMUData() {
   
    digitalWrite(primaryIMUSlaveSelectPin, LOW);

    // NEW SENSOR EVENT
    sensors_event_t accel;
    sensors_event_t gyro;
    sensors_event_t mag;
    sensors_event_t temp;
    imu.getEvent(&accel, &gyro, &mag);

    // STRUCT STORAGE
    prmIMUData data;
    data.acceleration[0] = accel.acceleration.x;
    data.acceleration[1] = accel.acceleration.y;
    data.acceleration[2] = accel.acceleration.z;

    data.magnetic[0] = mag.magnetic.x;
    data.magnetic[1] = mag.magnetic.y;
    data.magnetic[2] = mag.magnetic.z;

    data.gyro[0] = gyro.gyro.x;
    data.gyro[1] = gyro.gyro.y;
    data.gyro[2] = gyro.gyro.z;

    return data;

}