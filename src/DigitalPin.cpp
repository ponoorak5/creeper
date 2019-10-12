
#include <DigitalPin.h>

DigitalPin::DigitalPin(const DigitalPin& p)
:DigitalPin(p.pin(), p.mode())
{

}

DigitalPin::DigitalPin(int pin, PinMode mode)
:Pin(pin, mode)
{

}

void DigitalPin::write(PinState value)
{
    digitalWrite(pin(), value);
}

PinState DigitalPin::read()
{
    return (PinState)digitalRead(pin());
}

unsigned long DigitalPin::pulse(PinState value)
{
  return pulseIn(pin(), value);
}
