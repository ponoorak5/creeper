#include <Pin.h>
#include <Arduino.h>

Pin::Pin(const Pin& p)
{
  _pin = p._pin;
  _mode = p._mode;
}

Pin::Pin(int pin, PinMode mode)
:_pin(pin), _mode(mode)
{
    pinMode(_pin, _mode);
}
