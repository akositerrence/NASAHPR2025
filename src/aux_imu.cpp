#include <Arduino.h>
#include <Wire.h>
#include "aux_imu.h"
#include <Adafruit_ADXL375.h>
#include <Adafruit_Sensor.h>

Adafruit_ADXL375 aux_imu = Adafruit_ADXL375(12345);  
Adafruit_Sensor *aux_imu_accel; 

void aux_imu_initialize() {

    while (true) { 
        if(aux_imu.begin()) { break; } 
    } 

    aux_imu_accel = &aux_imu;

}

aux_imu_data read_aux_imu_data() {
    
    sensors_event_t aux_accel;

    aux_imu_data data;

    aux_imu_accel -> getEvent(&aux_accel);

    data.acceleration[0] = aux_accel.acceleration.x;
    data.acceleration[1] = aux_accel.acceleration.y;
    data.acceleration[2] = aux_accel.acceleration.z;

    return data;

}