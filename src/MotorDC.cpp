#include "MotorDC.h"

MotorDC::MotorDC(int pin1, int pin2, int epin)
    : _pin1(pin1, Output), _pin2(pin2, Output), _enable(epin, Output)

{
}

void MotorDC::speed(int s)
{
  _enable.write(s);
}

void MotorDC::forward()
{
  _pin1.write(High);
  _pin2.write(Low);
}

void MotorDC::back()
{
  _pin1.write(Low);
  _pin2.write(High);
}

void MotorDC::stop()
{
  _pin1.write(Low);
  _pin2.write(Low);
}
