#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduino.h>
#include "math/vector/vector.h"

// CONSTANTS
#define GEAR_DOWN 0
#define GEAR_UP 1

const float FLAPERON_RATIO_CONSTANT = 0.3; // 0 for flaperon mode off, 0.3 recommended
const float AILERON_POS_MIN = -70;
const float AILERON_POS_MAX = 70;
const float ELEVATOR_POS_MIN = -70;
const float ELEVATOR_POS_MAX = 70;
const float AUTOPILOT_DISENGAGE_THRESHOLD = 0.3; // 0 to 1, how "hard" input is needed to disengage AP. > 0.5 is dangerous.

const float KP_ROLL = 1; // FIXME: Tune!!!
const float KI_ROLL = 1; // FIXME: Tune!!!
const float KD_ROLL = 1; // FIXME: Tune!!!

const int RADIO_PIN_CE = 7;
const int RADIO_PIN_CSN = 8;

const int PIN_MOTOR_LEFT = 3;
const int PIN_MOTOR_RIGHT = 4;

enum ControlSurfaces
{
  AILERON_LEFT = 0,
  AILERON_RIGHT,
  ELEVATOR_LEFT,
  ELEVATOR_RIGHT,
  num_surface
};

// VARIABLES 
extern float flap;
extern float throttle;
extern float inputRoll; // from -1 to 1
extern float inputPitch; // from -1 to 1

// DETERMINED CONSTANTS


extern float turning_radius; // in meters


#endif