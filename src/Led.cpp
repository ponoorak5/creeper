#include <Led.h>

Led::Led()
:Led(-1)
{

}

 Led::Led(int pin)
 :Led(pin, 255)
 {
 }

Led::Led(int pin, int brightness)
:AnalogPin(pin), _brightness(brightness)
{

}

 void Led::brightness(int value)
 {
     AnalogPin::write(value);
 }

 void Led::on()
 {
     brightness(_brightness);
 }

 void Led::off()
 {
     AnalogPin::write(0);
 }