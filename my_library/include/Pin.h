#ifndef PIN_H
#define PIN_H

#include <Arduino.h>

enum PinMode
{
    Input = INPUT,
    Output = OUTPUT,
    PullUp = INPUT_PULLUP
};

class Pin
{
    public:
        Pin(const Pin &p);
        Pin(int pin, PinMode mode);
        const PinMode mode() const { return _mode; }
        const int pin () const { return _pin; }

    protected:

    private:
        int _pin;
        PinMode _mode;
};

#endif
