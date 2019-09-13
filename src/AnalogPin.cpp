#include <Arduino.h>
#include <AnalogPin.h>
#include <Pin.h>

AnalogPin::AnalogPin(int pin, PinMode mode)
: Pin(pin, mode)
{
}

int AnalogPin::read()
{
    return analogRead(pin());
}

void AnalogPin::write(int value)
{
    if (value < 0)
    {
        value = 0;
    }
    else if (value > 255)
    {
        value = 255;
    }
    
    analogWrite(pin(), value);
}
