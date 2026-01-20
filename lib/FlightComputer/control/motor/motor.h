#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>
#include <Servo.h>
#include "global/global.h"

struct Motor
{
  Servo motor; // This is NOT a servo lmao
  int PIN_SIGNAL;
  float offset; // Used for differential thrust

  void init();

  void SetThrottle();
};

extern Motor motors[2];

void UpdateThrottle();

#endif
