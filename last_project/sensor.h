#ifndef __sensor_h__
#define __sensor_h__
const int numReadings = 10;
class IR_sensor
{
  private:
    int pin;
    bool val;
  public:
    IR_sensor(int pin);
    bool detect();
};

const int smoke_tres = 150;
class Smoke_sensor
{
  private:
    int pin;
    int val;
   public:
    Smoke_sensor(int pin);
    int value();
    bool detect();
};

const int sound_tres = 100;
class Sound_sensor
{
  private:
    int pin;
    int val;
   public:
    Sound_sensor(int pin);
    int value();
    bool detect();
};

class buzzer
{
  private:
    int pin;
   public:
    buzzer(int pin);
    void on();
    void off();
};

class Ultrasonic_sensor
{
  private:
    int input_triggerpin;
    int input_echopin;
    int readings[numReadings];
    int readIndex = 0;
    int total = 0;                  // the running total
    int average = 0;                // the average
  public:
    Ultrasonic_sensor(int triggerpin, int echopin);
    int value();
};

class Photocell
{
  private:
    int pin;
    int readings[numReadings];
    int readIndex = 0;
    int total = 0;                  // the running total
    int average = 0;                // the average
  public:
    Photocell(int pin);
    int value();
};


#endif
