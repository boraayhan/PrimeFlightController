// LIBRARIES
#include <Arduino.h>
#include "communication/communication.h"
#include "control/motor/motor.h"
#include "control/control_surface/control_surface.h"
#include "autopilot/autopilot.h"
#include "global/global.h"

// FUNCTIONS

// Implement RF24 Signal Strength Check Algorithm (Send n packages, see how many arrive)
void InitializeSystems()
{
  SetupRadio();
  for (ControlSurface &s : surfaces)
  {
    s.init();
  }

  for (Motor &m : motors)
  {
    m.init();
  }
  Serial.println(F("Initialized!"));
}

void setup()
{
  Serial.begin(115200);
  InitializeSystems();
}

void loop()
{
  ReceiveRadio();
  UpdateThrottle();
  AutopilotPeriodic();
}

void UpdateControls()
{
  if(autopilotAxis[roll])
  {
    
  }
  else // 
  {
    MoveAilerons(inputRoll);
  }
  if(autopilotAxis[pitch])
  {

  }
  else
  {
    MoveElevators(inputPitch);
  }
}