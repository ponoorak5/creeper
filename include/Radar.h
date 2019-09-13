#ifndef RADAR_H
#define RADAR_H

#include <Arduino.h>
#include <Servo.h>

class Radar
{

public:
  Radar(const Servo &s);
  bool check();
private:
  Servo _s;

};

#endif
