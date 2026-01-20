#include "autopilot.h"

bool autopilot[3] = {false, false, false};

void DisengageAutopilot()
{
  autopilot[roll] = false;
  autopilot[pitch] = false;
  autopilot[yaw] = false;
}