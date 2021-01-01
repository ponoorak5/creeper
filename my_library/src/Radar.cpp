
#include <Arduino.h>
#include <AnalogPin.h>
#include <Radar.h>


Radar::Radar(const Servo &s, const EchoMeter& echo, int basePosition)
: _s(s), _echo(echo), _basePosition(basePosition)
{

}


float Radar::check(int rad)
{
  _s.write(rad + _basePosition);
  delay(200);
  return _echo.distanceCm();
}
