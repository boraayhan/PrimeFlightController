#ifndef AUTOPILOT_H
#define AUTOPILOT_H

#include <Arduino.h>
#include "global/global.h"
#include "sensors/gps/gps.h"
#include "math/vector/vector.h"

enum AutopilotDirections
{
    roll = 0,
    pitch,
    yaw
};

/*enum AutopilotState
{
    disabled = 0,
    calibrating,
    circle,
    hold,
    autoland
};
extern AutopilotState autopilotState;*/

extern bool autopilotAxis[3];
void AutopilotPeriodic();
void DisengageAutopilot();
bool DetermineTurningRadius();

#endif