#include <Arduino.h>
#include <Wire.h>
#include "bmp.h"
#include <Adafruit_BMP3XX.h>

Adafruit_BMP3XX bmp;

void bmp_initialize() {

    while (true) {
        if(bmp.begin_I2C()) { break; } 
    } 

    bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
    bmp.setPressureOversampling(BMP3_OVERSAMPLING_8X);
    bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
    bmp.setOutputDataRate(BMP3_ODR_50_HZ);

}

bmp_data read_bmp_data() {

    bmp_data data;

    bmp.performReading();

    data.temperature = bmp.temperature;
    data.pressure = bmp.pressure;
    data.altitude = bmp.readAltitude(1013.25);

    return data; 

}