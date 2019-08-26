#ifndef LED_H
#define LED_H

#include <Arduino.h>
#include <AnalogPin.h>

class Led : AnalogPin
{
    public:
        Led(int pin);
        Led(int pin, int brightness);
        void brightness(int value);
        void on();
        void off();
    private:
        int _brightness;
        int _pin;
    
};

#endif