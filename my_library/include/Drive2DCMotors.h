#ifndef DRIVE_2_MOTORS_DC_H
#define DRIVE_2_MOTORS_DC_H

#include <Arduino.h>
#include <MotorDC.h>

class Drive2DCMotors
{
    public:
        Drive2DCMotors(const MotorDC &l, const MotorDC &r);
        void forward();
        void back();
        void clockwise(bool inplace);
        void anticlockwise(bool inplace);
        void stop();
        void speed(int s);
      private:
        MotorDC _l;
        MotorDC _r;
};

#endif
