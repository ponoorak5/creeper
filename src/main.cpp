#include <Arduino.h>
#include <Drive2DCMotors.h>
#include <MotorDC.h>
#include <Led.h>
#include <LedRgb.h>
#include <Servo.h>
#include <dht.h>
// #include <Adafruit_Sensor.h>
 //#include <DHT.h>
//#include <DHT_U.h>

const int leftForward = 2;
const int leftBackward = 3;
const int rightForward = 4;
const int rightBackward = 5;



// dht DHT11;
//
// #define DHT11PIN 2    //przypisanie pinu 2 Arduino jako odczyt z sensora
// #define DHT113PIN 8

//Drive2DCMotors motor;
MotorDC motorLeft(2, 3, 6);
MotorDC motorRight(4, 5, 6);

Drive2DCMotors dc2(motorLeft, motorRight);

Servo myservo;
int pos = 0;
int s = 0;
int step = 20;
int dela = 1000;
void setup()
{
  Serial.begin(9600);
  //dth.setup(2);
//  myservo.attach(12);
  // int a = motor.add(3, 5);
}

void loop()
{
dc2.speed(155);
dc2.stop();

dc2.forward();
delay(2000);

dc2.back();
delay(2000);

dc2.clockwise(true);
delay(2000);

dc2.clockwise(false);
delay(2000);

dc2.stop();
delay(2000);

dc2.anticlockwise(true);
delay(2000);

dc2.anticlockwise(false);
delay(2000);
}
