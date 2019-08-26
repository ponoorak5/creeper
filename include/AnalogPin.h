#ifndef ANALOG_PIN_H
#define ANALOG_PIN_H

#include <Pin.h>

class AnalogPin : Pin
{
    public:        
       // AnalogPin();        
        AnalogPin(int pin, PinMode mode);
        // 0 and 1023
        int read();
        //0 to 255
        void write(int value);
};

#endif