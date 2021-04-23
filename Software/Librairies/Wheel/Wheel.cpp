/*
Wheel.cpp : A Library allowing to control the wheels of the robot Ghetto
*/

#include "Wheel.h"

Wheel::Wheel(int m_pinD, int m_pinE)
{
  pin_dir = m_pinD;
  pin_en = m_pinE;
  spd = 0;
  dir = HIGH;
}

void Wheel::wSetup() {
  pinMode(pin_dir, OUTPUT);
  pinMode(pin_en, OUTPUT);
}

void Wheel::setSpd(int m_spd) {
  spd = m_spd;
  analogWrite(pin_en, spd);
}

void Wheel::setDir(bool m_dir) {
  if (dir == m_dir) {}
  else {
    analogWrite(pin_en, spd / 2); delay(20);
    analogWrite(pin_en, 0); delay(20);
    dir = !dir;
  }
  digitalWrite(pin_dir, dir);
  analogWrite(pin_en, spd);
}
