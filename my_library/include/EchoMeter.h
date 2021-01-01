
#ifndef ECHOMETER_H
#define ECHOMETER_H

#include <Arduino.h>
#include <DigitalPin.h>

class EchoMeter
{
public:
  EchoMeter(int trig, int echo);
  float const distanceCm();

private:
  unsigned long pulse();
  DigitalPin _echo;
  DigitalPin _trigger;
};

#endif
