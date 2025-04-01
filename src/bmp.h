#ifndef BMP_H
#define BMP_H

struct BMPData {
    float pressure_temperature[2];
};

void BMPInitialize(int selectPin);
BMPData readBMPData();

#endif // BMP_H