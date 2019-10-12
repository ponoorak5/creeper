
#include <Arduino.h>
#include <AnalogPin.h>
#include <Radar.h>


Radar::Radar(const Servo &s, const EchoMeter& echo)
: _s(s), _echo(echo), _basePosition(0)
{

}


float Radar::check(int rad)
{
  _s.write(rad);
  delay(1000);
  return _echo.distanceCm();
}
