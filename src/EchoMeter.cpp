

#include <EchoMeter.h>

const float SoundSpeedCmUs = 0.034;

EchoMeter::EchoMeter(int trig, int echo)
:_trigger(trig, Output), _echo(echo, Input)
{

}

unsigned long EchoMeter::pulse()
{
    _trigger.write(Low);
    delayMicroseconds(2);

    _trigger.write(High);
    delayMicroseconds(10);
    _trigger.write(Low);

    return _echo.pulse(High);
}

float const EchoMeter::distanceCm()
{
  //return pulse();
  return pulse() * SoundSpeedCmUs / 2.0;
}
