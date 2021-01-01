#ifndef RADAR_H
#define RADAR_H

#include <Arduino.h>
#include <Servo.h>
#include <EchoMeter.h>

class Radar
{

public:
  Radar(const Servo &s, const EchoMeter &echo, int basePosition = 0);
  float check(int rad);
private:
  int _iDelay;
  Servo _s;
  EchoMeter _echo;
  int _basePosition;

};

#endif
