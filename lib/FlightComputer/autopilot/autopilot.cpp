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

DubinsPath::DubinsPath(Point s, Point f, Vector v, Vector finalDirection)
{
    pi = Point{add(pi.value, scalarMultiply(dubinsDelay, initVelocity.value))}; // Point to start turning;
    pf = f;
    initVelocity = v;
    dirF.value = unitVector(finalDirection.value);

}

