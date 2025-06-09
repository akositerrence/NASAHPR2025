#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include "primary_imu.h"
#include "aux_imu.h"
#include "bmp.h"
#include "gnss.h"

void setup() {
    
    Serial.begin(115200);
        while (!Serial) { delay(10); }

    Wire.begin();
    
    Serial.println("Serial 115200");

    primary_imu_initialize();
    Serial.println("ICM20948 Initialized");
    bmp_initialize();
    Serial.println("BMP390 Initialized");
    aux_imu_initialize();
    Serial.println("ADXL375 Initialized");
    gnss_initialize();
    Serial.println("NEOM9N Initialized");

}

void loop() {

    primary_imu_data icm20948 = read_primary_imu_data();
    aux_imu_data adxl375 = read_aux_imu_data();
    bmp_data bmp390 = read_bmp_data();
    gnss_data neom9n = read_gnss_data();

    Serial.print("ICM20948 : ");

    Serial.print(icm20948.temperature);
    Serial.print(" ");

    Serial.print(icm20948.acceleration[0]);
    Serial.print(" ");
    Serial.print(icm20948.acceleration[1]);
    Serial.print(" ");
    Serial.print(icm20948.acceleration[2]);
    Serial.print(" ");

    Serial.print(icm20948.magnetic[0]);
    Serial.print(" ");
    Serial.print(icm20948.magnetic[1]);
    Serial.print(" ");
    Serial.print(icm20948.magnetic[2]);
    Serial.print(" ");

    Serial.print(icm20948.gyro[0]);
    Serial.print(" ");
    Serial.print(icm20948.gyro[1]);
    Serial.print(" ");
    Serial.print(icm20948.gyro[2]);
    Serial.println(" ");

    Serial.print("ADXL375 : ");
    Serial.print(adxl375.acceleration[0]);
    Serial.print(" ");
    Serial.print(adxl375.acceleration[1]);
    Serial.print(" ");
    Serial.print(adxl375.acceleration[2]);
    Serial.println(" ");

    Serial.print("BMP390 : ");
    Serial.print(bmp390.temperature);
    Serial.print(" ");
    Serial.print(bmp390.pressure);
    Serial.print(" ");
    Serial.print(bmp390.altitude);
    Serial.println(" ");

    Serial.print("NEOM9N : ");
    Serial.print(neom9n.siv);
    Serial.print(" ");
    Serial.print(neom9n.latitude_longitude_altitude[0]);
    Serial.print(" ");
    Serial.print(neom9n.latitude_longitude_altitude[1]);
    Serial.println(" ");

}