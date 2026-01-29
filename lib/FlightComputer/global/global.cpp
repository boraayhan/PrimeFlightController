#include "global.h"

// Measured Quantities
Vector velocity = {{0, 0, 0}};
Point position = {{0, 0, 0}};

// Control Inputs
float flap = 0;
float throttle = 0;
float inputRoll = 0;
float inputPitch = 0;

// DETERMINED CONSTANTS
float turning_radius = 0; // in meters