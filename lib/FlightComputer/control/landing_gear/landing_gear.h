#ifndef LANDING_GEAR_H
#define LANDING_GEAR_H

#include <Arduino.h>
#include <Servo.h>

struct LandingGear
{

  Servo servo;
  int PIN_SIGNAL;
  float ANGLE_RETRACTED;
  float ANGLE_DEPLOYED;

  void enable()
  {
    servo.attach(PIN_SIGNAL);
    deploy();
  }

  void disable()
  {
    servo.detach();
  }

  void deploy()
  {
    servo.write(ANGLE_DEPLOYED);
  }

  void retract()
  {
    servo.write(ANGLE_RETRACTED);
  }
};

extern LandingGear gear[3];

void SetLandingGear(int state);

#endif