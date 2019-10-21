#include <Arduino.h>
#include <Drive2DCMotors.h>
#include <MotorDC.h>
#include <Led.h>
#include <LedRgb.h>
#include <Servo.h>
#include <dht.h>
#include <EchoMeter.h>
#include <Radar.h>

MotorDC motorLeft(2, 3, 6);
MotorDC motorRight(4, 5, 6);

Drive2DCMotors dc2(motorLeft, motorRight);

Servo myservo;
EchoMeter echo(9, 10);
Radar radar(myservo, echo, 90);



int pos = 0;
int dela = 2000;


void setup()
{
  Serial.begin(9600);
  myservo.attach(12);

  dc2.speed(120);
  dc2.stop();
}

void loop()
{


//delay(500);
  Serial.print("ost 0   ");
  Serial.println(radar.check(0));
  //delay(1000);


  if (radar.check(0) < 20)
  {
    dc2.stop();
    delay(1000);
    dc2.back();
  }
  else
  {
    dc2.forward();
  }



// Serial.print("Distance: ");
// Serial.println(echo.distanceCm());
// delay(1000);
//
// delay(500);
// Serial.print("ost 0   ");
// Serial.println(radar.check(0));
// delay(5000);
//
// Serial.print("ost 90  ");
// Serial.println(radar.check(90));
// delay(5000);
//
// Serial.print("ost -90 ");
// Serial.println(radar.check(-90));
// delay(5000);
//
// Serial.print("ost 20   ");
// Serial.println(radar.check(20));
// delay(5000);
//
// Serial.print("ost -40  ");
// Serial.println(radar.check(-40));
// delay(5000);

// Serial.print("ost 160 ");
// Serial.println(radar.check(160));
// delay(5000);
//
//
// Serial.print("ost-160 ");
// Serial.println(radar.check(-160));
// delay(5000);


  // for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //   // in steps of 1 degree
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15ms for the servo to reach the position
  // }
  // for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //   myservo.write(pos);              // tell servo to go to position in variable 'pos'
  //   delay(15);                       // waits 15ms for the servo to reach the position
  // }
  //
  //   myservo.write(0);
  //   delay(dela);
  //   myservo.write(90);
  //
  //   delay(dela);
  //   myservo.write(0);
  //
  //   delay(dela);
  //   myservo.write(30);
  //
  //   delay(dela);
  //   myservo.write(90);
  //
  // delay(dela);
  //
  //
  // myservo.write(0);
  // delay(dela);
  // myservo.write(90);
  //
  // delay(dela);
  // myservo.write(0);
  //
  // delay(dela);
  // myservo.write(70);
  //
  // delay(dela);
  // myservo.write(260);
  //
  // delay(dela);



  // dc2.speed(155);
  // dc2.stop();
  //
  // dc2.forward();
  // delay(dela);
  //
  // dc2.stop();
  // delay(dela);
  //
  // dc2.back();
  // delay(dela);
  //
  // dc2.stop();
  // delay(dela);
  //
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
  //
  // dc2.stop();
  // delay(dela);
}
