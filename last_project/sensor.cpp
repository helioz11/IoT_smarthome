#include <Arduino.h>
#include "sensor.h"
//***********************************************
IR_sensor::IR_sensor(int in_pin)
{
  pin = in_pin;
  pinMode(in_pin, INPUT);
  val = false;
}
bool IR_sensor::detect()
{
  val = digitalRead(pin);
  return val;
}
//***********************************************
//***********************************************
Smoke_sensor::Smoke_sensor(int in_pin)
{
  pin = in_pin;
}
int Smoke_sensor::value()
{
  val = analogRead(pin);
  return val;
}
bool Smoke_sensor::detect()
{
  val = analogRead(pin);
  return (val>smoke_tres);
}
//***********************************************
//***********************************************
Sound_sensor::Sound_sensor(int in_pin)
{
  pin = in_pin;
}
int Sound_sensor::value()
{
  val = analogRead(pin);
  return val;
}
bool Sound_sensor::detect()
{
  val = analogRead(pin);
  return (val>sound_tres);
}
//***********************************************
//***********************************************
buzzer::buzzer(int in_pin)
{
  pin = in_pin;
  pinMode(in_pin, OUTPUT);
}
void buzzer::on()
{
  digitalWrite(pin, HIGH);
}
void buzzer::off()
{
  digitalWrite(pin, LOW);
}
//***********************************************
//***********************************************
Ultrasonic_sensor::Ultrasonic_sensor(int triggerpin, int echopin)
{
  input_triggerpin = triggerpin;
  input_echopin = echopin;
  pinMode(triggerpin, OUTPUT);
  pinMode(echopin, INPUT);
}
int Ultrasonic_sensor::value()
{
  digitalWrite(input_triggerpin, LOW);
  delayMicroseconds(2);

  digitalWrite(input_triggerpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(input_triggerpin, LOW);
  
  // smoothing
  total = total - readings[readIndex];
  readings[readIndex] = pulseIn(input_echopin, HIGH)/58.2;
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }
  // calculate the average:
  average = total / numReadings;
  return average;
}
//***********************************************
//***********************************************
Photocell::Photocell(int in_pin)
{
  pin = in_pin;
}
int Photocell::value()
{
  // smoothing
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(pin);
  total = total + readings[readIndex];
  readIndex = readIndex + 1;

  // if we're at the end of the array...
  if (readIndex >= numReadings) {
    // ...wrap around to the beginning:
    readIndex = 0;
  }
  // calculate the average:
  average = total / numReadings;
  return average;
}
//***********************************************
