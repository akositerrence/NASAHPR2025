#include <Arduino.h>
#include <Wire.h>
#include "primary_imu.h"
#include <Adafruit_ICM20X.h>
#include <Adafruit_ICM20948.h>
#include <Adafruit_Sensor.h>

Adafruit_ICM20948 imu;  
Adafruit_Sensor *imu_temp, *imu_accel, *imu_gyro, *imu_mag; 

void primary_imu_initialize() {

    while (true) {
        if(imu.begin_I2C()) { break; } 
    } 

    imu_temp = imu.getTemperatureSensor();
    imu_accel = imu.getAccelerometerSensor();
    imu_gyro = imu.getGyroSensor();
    imu_mag = imu.getMagnetometerSensor();

}

primary_imu_data read_primary_imu_data() {
    
    sensors_event_t accel;
    sensors_event_t gyro;
    sensors_event_t temp;
    sensors_event_t mag;

    primary_imu_data data;

    imu_temp -> getEvent(&temp);
    imu_accel -> getEvent(&accel);
    imu_gyro -> getEvent(&gyro);
    imu_mag -> getEvent(&mag);

    data.temperature = temp.temperature;

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