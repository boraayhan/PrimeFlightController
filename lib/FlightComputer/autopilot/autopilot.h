#ifndef AUTOPILOT_H
#define AUTOPILOT_H

#include <Arduino.h>
#include "../global/global.h"
#include "../sensors/gps/gps.h"

enum AutopilotDirections
{
    roll = 0,
    pitch,
    yaw
};

enum AutopilotState
{
    disabled = 0,
    circle,
    hold,
    autoland
};

extern bool autopilotAxis[3];
extern AutopilotState autopilotState;

void DisengageAutopilot();
void AutopilotPeriodic();
bool DetermineTurningRadius();
void RollAutopilot();
void PitchAutopilot();
void YawAutopilot();
#endif