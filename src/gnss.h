#ifndef gnss_h
#define gnss_h
#include <cstdint>

struct gnss_data {
    float latitude_longitude_altitude[2];
    uint8_t time[5];
    uint16_t year;
    int siv;
};

void gnss_initialize();
gnss_data read_gnss_data();

#endif 