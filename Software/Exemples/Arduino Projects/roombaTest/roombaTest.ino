#include <Wheel.h>

#define DIR_R 3
#define DIR_L 5
#define EN_R 2
#define EN_L 4

#define bumperF 29
#define bumperR 33
//#define bumperL 37
#define bumperB 41

bool robotState = 1;

Wheel rightWheel(DIR_R, EN_R);
Wheel leftWheel(DIR_L, EN_L);

void setup() {
  Serial.begin(9600);
  rightWheel.wSetup();
  leftWheel.wSetup();

  pinMode(bumperF,INPUT_PULLUP);
  pinMode(bumperR,INPUT_PULLUP);
//  pinMode(bumperL,INPUT_PULLUP);
  pinMode(bumperB,INPUT_PULLUP);
}

void loop() {
  if(digitalRead(bumperF)==LOW){fallbackF();}
  else if(digitalRead(bumperR)==LOW){fallbackR();}
//  else if(digitalRead(bumperL)==LOW){fallbackL();}
  else if(digitalRead(bumperB)==LOW){fallbackB();}
  else if (robotState){
    goForward();
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

//FONCTIONS BUMPER
void fallbackF() {
  goStop();goBack();delay(500);goLeft();delay(500);goStop();
  if (!robotState){
    robotState = !robotState;
  }
}
void fallbackB() {
  goStop();
  robotState = !robotState;
}
void fallbackR() {
  goStop();goBack();delay(500);goLeft();delay(1000);goStop();
  if (!robotState){
    robotState = !robotState;
  }
}
void fallbackL() {
  goStop();goRight();delay(500);goForward();delay(1000);goStop();
  if (!robotState){
    robotState = !robotState;
  }
}
