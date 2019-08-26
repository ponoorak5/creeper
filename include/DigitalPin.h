#ifndef DIGITAL_PIN_H
#define DIGITAL_PIN_H
#include <Arduino.h>
#include <Pin.h>

enum PinState
{
    High = HIGH,
    Low = LOW
};

class DigitalPin : Pin
{
    public:
        DigitalPin(int pin, PinMode mode);
        void write(PinState value);
        PinState read();
};

#endif