
#include "Drive2DCMotors.h"

Drive2DCMotors::Drive2DCMotors(const MotorDC &l, const MotorDC &r)
: _l(l), _r(r)
{

}

void Drive2DCMotors::forward()
{
  _l.forward();
  _r.forward();
}

void Drive2DCMotors::back()
{
  _l.back();
  _r.back();
}

void Drive2DCMotors::clockwise(bool inplace)
{
  _l.forward();
  if (inplace)
  {
    _r.back();
  }
  else
  {
    _r.stop();
  }
}

void Drive2DCMotors::anticlockwise(bool inplace)
{
  _l.back();
  if (inplace)
  {
    _r.forward();
  }
  else
  {
    _l.stop();
  }
}

void Drive2DCMotors::stop()
{
  _l.stop();
  _r.stop();
}

void Drive2DCMotors::speed(int s)
{
  _l.speed(s);
  _r.speed(s);
}
