#include "autopilot.h"

bool autopilotAxis[3] = {false, false, false};

void DisengageAutopilot()
{
    autopilotAxis[roll] = false;
    autopilotAxis[pitch] = false;
    autopilotAxis[yaw] = false;
}

void AutopilotPeriodic()
{
}

void ComputeDSDPath() {
    Point c1 = {{0, 0, 0}};
}