#include <Arduino.h>
#include <Drive2DCMotors.h>
#include <MotorDC.h>
#include <Led.h>
#include <LedRgb.h>

const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;

//Drive2DCMotors motor;
MotorDC motor1(2, 3, 6);
MotorDC motor2(4, 5, 6);
Led led(9);
LedRgb rgb(9, 10, 11);

int s = 0;
int step = 20;
int dela = 1000;
void setup() 
{
  Serial.begin(9600);
 // int a = motor.add(3, 5);
}

void loop()
{
  if (s < 0)
  {
   step = -step;
   rgb.off();
  }

  if (s > 255)
  {
    step = -step;
    rgb.off();
  }
  
  rgb.r(255);
  delay(dela);

  rgb.g(255);  
  delay(dela);

  rgb.b(255);
  delay(dela);

  rgb.off();
  delay(dela);

  rgb.r(255);
  rgb.g(255);
  rgb.b(255);
  delay(dela);

  rgb.r(100);
  rgb.g(100);
  rgb.b(100);

  s += step; 

  Serial.println(s);
  Serial.println(step);
  motor1.speed(s);
  motor2.speed(s);
  motor1.forward();
  motor2.forward();
  delay(dela);
  motor1.stop();
  motor2.stop();
  delay(dela);
  motor1.back();
  motor2.back();
  delay(dela);
  motor1.stop();
  motor2.stop();
  delay(dela);
 
}
