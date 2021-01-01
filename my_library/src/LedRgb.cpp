#include <LedRgb.h>

LedRgb::LedRgb(int r_pin, int g_pin, int b_pin)
:_r(r_pin), _g(g_pin), _b(b_pin)
{

}

void LedRgb::r(byte value)
{
    _r.brightness(value);
}

void LedRgb::g(byte value)
{
     _g.brightness(value);
}

void LedRgb::b(byte value)
{
     _b.brightness(value);
}

void LedRgb::off()
{
    _r.off();
    _g.off();
    _b.off();
}