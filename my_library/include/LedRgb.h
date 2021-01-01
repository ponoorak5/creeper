#ifndef LED_RGB_H
#define LED_RGB_H

#include <Led.h>
#include <LedRgb.h>

class LedRgb
{
    private:
    Led _r;
    Led _g;
    Led _b;
    public:
        LedRgb(int r_pin, int g_pin, int b_pin);
        void r(byte value);
        void g(byte value);
        void b(byte value);
        void off();

};

#endif