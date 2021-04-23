/*
Wheel.h : A Library allowing to control the wheels of the robot Ghetto
*/
#ifndef Wheel_h
#define Wheel_h

#include "Arduino.h"

class Wheel {
  private:
    int pin_dir;
    int pin_en;
    int spd;
    bool dir;

  public:
    Wheel(int m_pinD, int m_pinE);
    void wSetup();
    void setSpd(int m_speed);
    void setDir(bool m_dir);
};

#endif
