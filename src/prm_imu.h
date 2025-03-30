#ifndef PRM_IMU_H
#define PRM_IMU_H

struct prmIMUData {
    float acceleration[3];
    float magnetic[3];
    float gyro[3];
};

void prmIMUInitialize(int selectPin);
prmIMUData readPrmIMUData();

#endif // PRM_IMU_H