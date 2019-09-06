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



dht DHT11;

#define DHT11PIN 2    //przypisanie pinu 2 Arduino jako odczyt z sensora

//Drive2DCMotors motor;
MotorDC motor1(2, 3, 6);
MotorDC motor2(4, 5, 6);



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
  int chk = DHT11.read11(DHT11PIN);         //sprawdzenie stanu sensora, a następnie wyświetlenie komunikatu na monitorze szeregowym

  Serial.print("Stan sensora: ");
  switch (chk)
  {
    case DHTLIB_OK:
		Serial.print("OKt");
		break;
    case DHTLIB_ERROR_CHECKSUM:
		Serial.println("Błąd sumy kontrolnej");
		break;
    case DHTLIB_ERROR_TIMEOUT:
		Serial.println("Koniec czasu oczekiwania - brak odpowiedzi");
		break;
    default:
		Serial.println("Nieznany błąd");
		break;
  }
  Serial.print("Wilgotnosc (%): ");              //wyświetlenie wartości wilgotności
  Serial.print((float)DHT11.humidity, 2);
  Serial.print("tt");
  Serial.print("Temperatura (C): ");           //wyświetlenie temperatury
  Serial.println((float)DHT11.temperature, 2);

  delay(1000);
}
  // for (pos = 0; pos <= 180; pos += 1) // obrót od 0 do 180 stopni
  // {                                   // w krokach co 1 stopień
  //   myservo.write(pos);               // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
  //   delay(15);                        // poczekaj 15ms, aby serwo osiągnęło ustaloną pozycje
  // }
  // for (pos = 180; pos >= 0; pos -= 1) // obrót od 180 do 0 stopni
  // {
  //   myservo.write(pos); // przekazanie do serwa obrotu o tyle ile jest zapisane w zmiennej 'pos'
  //   delay(15);          // poczekaj 15ms, aby serwo osiągnęło ustaloną pozycje
  // }

  // delay(1000);
  // myservo.write(90);
  // delay(3000);
  // if (s < 0)
  // {
  //  step = -step;

  // }

  // if (s > 255)
  // {
  //   step = -step;

  // }

  // s = 200;

  // motor1.forward();
  // motor2.forward();
  // motor1.speed(20);
  // delay(2000);

  // motor1.speed(20);
  // motor2.speed(20);
  // delay(2000);

  // motor1.speed(50);
  // motor2.speed(50);
  // delay(2000);

  // motor1.speed(100);
  // motor2.speed(100);
  // delay(2000);

  // motor1.speed(150);
  // motor2.speed(150);
  // delay(2000);

  // motor1.speed(200);
  // motor2.speed(200);
  // delay(2000);

  // motor1.speed(255);
  // motor2.speed(255);
  // delay(2000);

  // Serial.println(s);
  // Serial.println(step);
  // motor1.speed(s);
  // motor2.speed(s);
  // motor1.forward();
  // motor2.forward();
  // delay(dela);
  // motor1.stop();
  // motor2.stop();
  // delay(dela);
  // motor1.back();
  // motor2.back();
  // delay(dela);
  // motor1.stop();
  // motor2.stop();
  // delay(dela);
//}
