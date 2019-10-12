#ifndef RADAR_H
#define RADAR_H

#include <Arduino.h>
#include <Servo.h>
#include <EchoMeter.h>

class Radar
{

public:
  Radar(const Servo &s, const EchoMeter &echo);
  float check(int rad);
private:
  Servo _s;
  EchoMeter _echo;
  int _basePosition;

};

#endif
