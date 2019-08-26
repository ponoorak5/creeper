#ifndef MOTOR_DC_H
#define MOTOR_DC_H

#include <Arduino.h>
#include <AnalogPin.h>
#include <DigitalPin.h>

class MotorDC
{
    public:
        MotorDC(int pin1, int pin2);
        MotorDC(int pin1, int pin2, int epin);
        void forward();
        void back();
        void stop();
        void speed(int s);
    private:
        DigitalPin _pin1;
        DigitalPin _pin2;        
        AnalogPin _enable; 
};

#endif