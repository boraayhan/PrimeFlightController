#include "autopilot.h"

bool autopilotAxis[3] = {false, false, false};

int autoPilotState = disabled;

void DisengageAutopilot()
{
    autopilotAxis[roll] = false;
    autopilotAxis[pitch] = false;
    autopilotAxis[yaw] = false;
}

void AutopilotPeriodic()
{
    
    switch (autoPilotState)
    {
    case disabled:
        break;
    case circle:
        break;
    case hold:
        if (autopilotAxis[roll])
        {
            RollAutopilot();
        }
        if (autopilotAxis[pitch])
        {
            PitchAutopilot();
        }
        if (autopilotAxis[yaw])
        {
            YawAutopilot();
        }
        break;
    case autoland:
        break;
    }
}

bool DetermineTurningRadius()
{
    Coordinate p1 = GetPosition();

    Coordinate p2 = GetPosition();
    return false;
}

void RollAutopilot()
{
    
}
void PitchAutopilot()
{

}

void YawAutopilot()
{
    
}