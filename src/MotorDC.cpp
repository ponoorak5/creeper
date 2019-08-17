
#include "MotorDC.h"

MotorDC::MotorDC(int pin1, int pin2)
: MotorDC(pin1, pin2, -1)
{

}

MotorDC::MotorDC(int pin1, int pin2, int epin)
:_pin1(pin1), _pin2(pin2), AnalogPin(epin)
{
    pinMode(_pin1 , OUTPUT);
    pinMode(_pin2 , OUTPUT);
}

void MotorDC::speed(int s)
{ 
  AnalogPin::write(s);  
}

void MotorDC::forward()
{
  digitalWrite(_pin1 , HIGH);
  digitalWrite(_pin2 , LOW);
}
 
void MotorDC::back()
{
  digitalWrite(_pin1 , LOW);
  digitalWrite(_pin2 , HIGH);
}

void MotorDC::stop()
{
  digitalWrite(_pin1 , LOW);
  digitalWrite(_pin2 , LOW);
}