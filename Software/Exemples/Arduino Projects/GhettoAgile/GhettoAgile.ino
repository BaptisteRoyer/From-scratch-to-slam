#include <Wheel.h>

#define DIR_R 3
#define DIR_L 5
#define EN_R 2
#define EN_L 4

Wheel rightWheel(DIR_R, EN_R);
Wheel leftWheel(DIR_L, EN_L);

void setup() {
  Serial.begin(9600);
  rightWheel.wSetup();
  leftWheel.wSetup();
}

void loop() {
  if (Serial.available() > 0)
  {
    char val = Serial.read();
    switch (val)
    {
      case 'z':
        goForward();
        break;
      case 'q':
        goLeft();
        break;
      case 's':
        goBack();
        break;
      case 'd':
        goRight();
        break;
      case 'x':
        goStop();
        break;
      case 'c':
        Serial.println("Go Square");
        for (int i = 0; i < 4; i++) {
          goForward();
          delay(2000);
          goLeft();
          delay(1000);
        }
        goStop();
        break;
      case 'o':
        Serial.println("Go Circle");
        rightWheel.setSpd(210);
        leftWheel.setSpd(180);
        delay(3000);
        goStop();
        break;
      default:
        break;
    }
  }
}

//FONCTIONS DE DEPLACEMENT
void goForward() {
  rightWheel.setDir(LOW); leftWheel.setDir(HIGH);
  rightWheel.setSpd(200); leftWheel.setSpd(200);
}
void goRight() {
  rightWheel.setDir(HIGH); leftWheel.setDir(HIGH);
  rightWheel.setSpd(200); leftWheel.setSpd(200);
}
void goLeft() {
  rightWheel.setDir(LOW); leftWheel.setDir(LOW);
  rightWheel.setSpd(200); leftWheel.setSpd(200);
}
void goBack() {
  rightWheel.setDir(HIGH); leftWheel.setDir(LOW);
  rightWheel.setSpd(200); leftWheel.setSpd(200);
}
void goStop() {
  rightWheel.setSpd(0);
  leftWheel.setSpd(0);
}
