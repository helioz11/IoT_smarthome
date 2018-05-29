//INCLUDE YOUR FILE HERE
#include "sensor.h"
#include "dht.h"
#include <Wire.h>
#include "GY80.h"

//DECLARE YOUR PIN HERE
const int IR_pin = 8;
const int dht_pin = A0;
const int trig_pin = 7;
const int echo_pin = 8;
const int photocell_pin = A0;

//INITIALIZE YOUR SENSOR HERE
IR_sensor infrared_dig(IR_pin);
Smoke_sensor smoke_analog(0);
Sound_sensor sound_analog(0);
buzzer buzz_dig(2);
Ultrasonic_sensor ultrasonic_dig(trig_pin, echo_pin);
dht dht11_analog;
Photocell photo_sensor(photocell_pin);
GY80 sensor = GY80(); //create GY80 instance


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("Photocell : ");
  Serial.println(photo_sensor.value());
  /*GY80 Accelerometer
  Serial.print("x value: ");
  Serial.print(g_value.a_x);
  Serial.print("\ty value: ");
  Serial.print(g_value.a_y);
  Serial.print("\tz value: ");
  Serial.println(g_value.a_z);
  */
  /* DHT11
  dht11_analog.read11(dht_pin);  
  Serial.print("Current humidity = ");
  Serial.print(dht11_analog.humidity);
  Serial.print("% ");
  Serial.print("temperature = ");
  Serial.print(dht11_analog.temperature);
  Serial.println("C ");
  delay(1000);   //data update period
  */
  /* Distance
  Serial.print("Distance : ");
  Serial.println(ultrasonic_dig.value());
  */
  int a=sound_analog.detect();
  //Serial.println(sound_analog.detect());
  //delay(sound_analog.detect());
}
