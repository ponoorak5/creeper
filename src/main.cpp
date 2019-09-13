#include <Arduino.h>
#include <Drive2DCMotors.h>
#include <MotorDC.h>
#include <Led.h>
#include <LedRgb.h>
#include <Servo.h>
#include <dht.h>
#include <Radar.h>

MotorDC motorLeft(2, 3, 6);
MotorDC motorRight(4, 5, 6);

Drive2DCMotors dc2(motorLeft, motorRight);

Servo myservo;

Radar radar(myservo);

int dela = 2000;
void setup()
{
  Serial.begin(9600);
  myservo.attach(12);
}

void loop()
{

  myservo.write(180);
  delay(dela);
  myservo.write(90);

  delay(dela);
  myservo.write(0);

delay(dela);
//   dc2.stop();
//
// dc2.speed(155);
// dc2.stop();
//
// dc2.forward();
// delay(dela);
// dc2.stop();
// delay(dela);
//
// dc2.back();
// delay(dela);
// dc2.stop();
// delay(dela);
// dc2.stop();
//
// dc2.clockwise(true);
// delay(dela);
//
// dc2.clockwise(false);
// delay(dela);
//
// dc2.stop();
// delay(dela);
//
// dc2.anticlockwise(true);
// delay(dela);
//
// dc2.anticlockwise(false);
// delay(dela);
}
