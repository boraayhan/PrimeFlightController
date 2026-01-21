#ifndef PID_H
#define PID_H
#include <Arduino.h>

class pid
{
public:
    float compute(float input, float target);
    pid(float KP, float KI, float KD);

private:
    float kP;
    float kI;
    float kD;
    float error;
    unsigned long now;
    float prevError;
    float prevTime;
    float integral;
    float derivative;
};

#endif