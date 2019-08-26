#include <Pin.h>
#include <Arduino.h>

Pin::Pin(int pin, PinMode mode)
:_pin(pin), _mode(mode) 
{
    pinMode(_pin, _mode);
}