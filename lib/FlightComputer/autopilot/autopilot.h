#ifndef AUTOPILOT_H
#define AUTOPILOT_H

#include <Arduino.h>

enum AutopilotDirections
{
    roll = 0,
    pitch,
    yaw
};

extern bool autopilot[3];

void DisengageAutopilot();


#endif