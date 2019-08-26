#include <Led.h>
#include <Pin.h>


 Led::Led(int pin)
 :Led(pin, 255)
 {
 }

Led::Led(int pin, int brightness)
:AnalogPin(pin, Output), _brightness(brightness)
{

}

 void Led::brightness(int value)
 {
     _brightness = value;
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