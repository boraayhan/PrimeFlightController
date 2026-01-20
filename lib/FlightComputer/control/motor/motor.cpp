#include "motor.h"
void Motor::init()
{
    motor.attach(PIN_SIGNAL);
    motor.writeMicroseconds(1000);
}

void Motor::SetThrottle()
{
    float speed = constrain(1000 + offset + 1000 * throttle, 1000, 2000);
    motor.writeMicroseconds(speed);
}

Motor motors[2] = {
    {Servo(), PIN_MOTOR_LEFT, 0},
    {Servo(), PIN_MOTOR_RIGHT, 0},
};

void UpdateThrottle()
{
  for (Motor &m : motors)
  {
    m.SetThrottle();
  }
}