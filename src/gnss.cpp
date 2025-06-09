#include <gnss.h>
#include <Arduino.h>
#include <TinyGPSPlus.h>

#define gnss_port Serial1
#define gnss_baud 9600

TinyGPSPlus gnss;

double latitude = 0.0;
double longitude = 0.0;
double altitude = 0.0;
uint8_t siv = 0;

uint16_t year = 0;
uint8_t month = 0;
uint8_t day = 0;
uint8_t hour = 0;
uint8_t minute = 0;
uint8_t second = 0;

void gnss_initialize() {
    gnss_port.begin(gnss_baud);
}

gnss_data read_gnss_data() {

    while (gnss_port.available()) {
        char c = gnss_port.read();
        gnss.encode(c);
    }

    latitude = gnss.location.lat();
    longitude = gnss.location.lng();

    altitude = gnss.altitude.meters(); 

    siv = gnss.satellites.value();

    year = gnss.date.year();
    month = gnss.date.month();
    day = gnss.date.day();
    hour = gnss.time.hour();
    minute = gnss.time.minute();
    second = gnss.time.second();

    gnss_data data;
    data.latitude_longitude_altitude[0] = latitude;
    data.latitude_longitude_altitude[1] = longitude;
    data.latitude_longitude_altitude[2] = altitude;

    data.time[0] = month;
    data.time[1] = day;
    data.time[2] = hour;
    data.time[3] = minute;
    data.time[4] = second;

    data.year = year;

    data.siv = siv;

    return data;

}