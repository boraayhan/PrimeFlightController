#ifndef GLOBAL_H
#define GLOBAL_H

#include <Arduino.h>
#include "math/vector/vector.h"

const float FLAPERON_RATIO_CONSTANT = 0.3; // 0 for flaperon mode off, 0.3 recommended
const float AILERON_POS_MIN = -70;
const float AILERON_POS_MAX = 70;
const float ELEVATOR_POS_MIN = -70;
const float ELEVATOR_POS_MAX = 70;
const float KP_ROLL = 1; // FIXME: Tune!!!
const float KI_ROLL = 1; // FIXME: Tune!!!
const float KD_ROLL = 1; // FIXME: Tune!!!

const float AUTOPILOT_DISENGAGE_THRESHOLD = 0.3; // 0 to 1, how "hard" input is needed to disengage AP. > 0.5 is dangerous.
const float dubinsDelay = 1; // Seconds, delay between calculating a dubins path to executing it (since calculation takes nonzero time) to avoid delay loop
const int RADIO_PIN_CE = 7;
const int RADIO_PIN_CSN = 8;

const int PIN_MOTOR_LEFT = 3;
const int PIN_MOTOR_RIGHT = 4;

// VARIABLES 
extern Vector velocity;
extern Point position;
extern float flap;
extern float throttle;
extern float inputRoll; // from -1 to 1
extern float inputPitch; // from -1 to 1

// DETERMINED CONSTANTS


extern float turning_radius; // in meters


#endif