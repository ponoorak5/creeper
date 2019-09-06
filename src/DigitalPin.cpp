
#include <DigitalPin.h>

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
