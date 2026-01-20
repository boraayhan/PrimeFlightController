#ifndef COMMUNICATION_H
#define COMMUNICATION_H

#include <Arduino.h>
#include <RF24.h>
#include "global/global.h"
#include "control/control_surface/control_surface.h"
#include "autopilot/autopilot.h"

extern uint8_t address[][6];

struct RadioPayload
{
  int32_t id;
  float p1;
  float p2;
};

extern RF24 radio;
extern RadioPayload radioPayload;

void ReceiveRadio();
void SetupRadio();

#endif
