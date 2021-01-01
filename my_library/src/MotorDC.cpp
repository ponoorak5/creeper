#include "MotorDC.h"

MotorDC::MotorDC(const MotorDC& c)
:MotorDC(c._pin1.pin(), c._pin2.pin(), c._enable.pin())
{
}

MotorDC::MotorDC(int pin1, int pin2, int epin)
    : _pin1(pin1, Output), _pin2(pin2, Output), _enable(epin, Output)

{
}

void MotorDC::speed(int s)
{
  _speed = s;
  _enable.write(s);
}

void MotorDC::forward()
{
  //speed(_speed);
  _pin1.write(High);
  _pin2.write(Low);
}

void MotorDC::back()
{
  //speed(_speed);
  _pin1.write(Low);
  _pin2.write(High);
}

void MotorDC::stop()
{
  //speed(0);
  _pin1.write(Low);
  _pin2.write(Low);
}
