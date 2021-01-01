#ifndef DIGITAL_PIN_H
#define DIGITAL_PIN_H
#include <Arduino.h>
#include <Pin.h>

enum PinState
{
    High = HIGH,
    Low = LOW
};

class DigitalPin : public Pin
{
    public:
        DigitalPin(const DigitalPin& p);
        DigitalPin(int pin, PinMode mode);
        void write(PinState value);
        PinState read();
        unsigned long pulse(PinState value);
};

#endif
