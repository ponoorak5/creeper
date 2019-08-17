#ifndef MOTOR_DC_H
#define MOTOR_DC_H

#include <Arduino.h>
#include <AnalogPin.h>

class MotorDC : AnalogPin
{
    public:
        MotorDC(int pin1, int pin2);
        MotorDC(int pin1, int pin2, int epin);
        void forward();
        void back();
        void stop();
        void speed(int s);
    private:
        int _pin1;
        int _pin2;      
        AnalogPin _enable; 
};

#endif