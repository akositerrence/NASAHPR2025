#ifndef aux_imu_h
#define aux_imu_h

struct aux_imu_data {
    float acceleration[3];
};

void aux_imu_initialize();
aux_imu_data read_aux_imu_data();

#endif