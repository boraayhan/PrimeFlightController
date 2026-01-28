#ifndef CONTROL_SURFACE_H
#define CONTROL_SURFACE_H

#include <Arduino.h>
#include <Servo.h>
#include "global/global.h"

struct ControlSurface
{
  Servo servo;
  int PIN_SIGNAL;
  float zero;
  float trimAngle;
  float min;
  float max;
  int dir; // +1 or -1 to correct for rotational symmetry
  void init();
  void test();
  void move(float angle);
  void trim(float angle);
};

void MoveAilerons(float jR);
void MoveElevators(float jP);

extern ControlSurface surfaces[num_surface];

void SetBankAngle(float angle);
void SetPitchAngle(float angle);

void TestSurfaces();
#endif
