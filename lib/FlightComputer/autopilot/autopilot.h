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

enum DubinsPathType
{
    LSL,
    LSR,
    RSL,
    RSR
};

struct DubinsPath {
    Point pi; // Point where path STARTS, not where path is created! = currentPos + vel * tdelay
    Point pf;
    Vector initVelocity; // Also dirI
    Vector dirF;
    Point C1;
    Point C2;
    DubinsPathType type;

    DubinsPath(Point s, Point f, Vector v, Vector finalDirection);
    void DetermineOptimalPath();
};

extern bool autopilotAxis[3];
void AutopilotPeriodic();
void DisengageAutopilot();
bool DetermineTurningRadius();

#endif