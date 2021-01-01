#include <Arduino.h>
#include <Drive2DCMotors.h>
#include <MotorDC.h>
#include <Led.h>
#include <LedRgb.h>
//#include <Servo.h>
//#include <dht.h>
#include <EchoMeter.h>
#include <Radar.h>
#include <NewPing.h>

#define TRIGGER_PIN  7  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     6  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 100 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.



//MotorDC motorLeft(2, 3, 6);
//MotorDC motorRight(4, 5, 6);

//Drive2DCMotors dc2(motorLeft, motorRight);

//Servo myservo;
EchoMeter echo(7, 6);
//Radar radar(myservo, echo, 90);



int pos = 0;
int dela = 2000;
int distance = 20;

void setup()
{
   Serial.begin(9600);
  // myservo.attach(12);

  // dc2.speed(120);
  // dc2.stop();
}


// int CheckRadar()
// {
//   if (radar.check(60) > distance)
//   {
//     return 1;
//   }

//   if (radar.check(-60) > distance)
//   {
//     return 2;
//   }

//   return 0;
// }

void loop()
{
delay(500);
  // Serial.print("distance = ");
  // Serial.print(echo.distanceCm());
  // Serial.print("  cm");
  // Serial.println();
  Serial.print("Ping: ");
  Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  Serial.println("cm");

  //Serial.println(radar.check(0));
  //delay(1000);


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
