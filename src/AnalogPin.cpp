#include <Arduino.h>
#include <AnalogPin.h>

// AnalogPin::AnalogPin()
// :AnalogPin(-1)
// {

// }
AnalogPin::AnalogPin()
{

}

AnalogPin::AnalogPin(int pin, bool write)
: _pin(pin)
{
    if (write)
    {
        pinMode(_pin, OUTPUT);
    }
    else
    {
        pinMode(_pin, INPUT);
    }
}

int AnalogPin::read()
{
    return analogRead(_pin);
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

    analogWrite(_pin, value);
}

