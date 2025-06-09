#ifndef primary_imu_h
#define primary_imu_h

struct primary_imu_data {
    float temperature;
    float acceleration[3];
    float magnetic[3];
    float gyro[3];
};

void primary_imu_initialize();
primary_imu_data read_primary_imu_data();

#endif