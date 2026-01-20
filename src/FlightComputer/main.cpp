// LIBRARIES
#include <Arduino.h>
#include "communication/communication.h"
#include "control/motor/motor.h"
#include "control/control_surface/control_surface.h"

// FUNCTIONS

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
  /*if (autopilot[roll])
  { // Maintains zero bank angle
    RollAutopilot();
  }
  if (autopilot[pitch])
  {
  }*/
}