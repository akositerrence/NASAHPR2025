#ifndef bmp_h
#define bmp_h

struct bmp_data {
    float temperature;
    float pressure;
    float altitude;
};

void bmp_initialize();
bmp_data read_bmp_data();

#endif