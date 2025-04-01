#include <bmp.h>
#include <Arduino.h>
#include <SPI.h>
#include <Adafruit_BMP3XX.h>

Adafruit_BMP3XX bmp;    // CREATE SENSOR OBJECT
int BMPSlaveSelectPin;   // GLOBAL SELECT PIN

void BMPInitialize(int selectPin) {

    BMPSlaveSelectPin = selectPin;   // RECEIVE SELECT PIN
    digitalWrite(BMPSlaveSelectPin, HIGH);

    // SPI SANITY CHECK
    Serial.println("Attempting BMP390 SPI initialization...");
    if (!bmp.begin_SPI(BMPSlaveSelectPin)) {
      Serial.println("Failed to initialize BMP390 via SPI");
    }
    Serial.println("BMP390 SPI initialization successful");

    // SET BMP390 CONFIGURATION
    bmp.setTemperatureOversampling(BMP3_OVERSAMPLING_8X);
    bmp.setPressureOversampling(BMP3_OVERSAMPLING_4X);
    bmp.setIIRFilterCoeff(BMP3_IIR_FILTER_COEFF_3);
    bmp.setOutputDataRate(BMP3_ODR_50_HZ);
}

BMPData readBMPData() {
   
    digitalWrite(BMPSlaveSelectPin, LOW);

    // NEW SENSOR EVENT
    bmp.performReading();

    // STRUCT STORAGE
    BMPData data;
    data.pressure_temperature[0] = bmp.pressure;
    data.pressure_temperature[1] = bmp.temperature;

    return data;

}