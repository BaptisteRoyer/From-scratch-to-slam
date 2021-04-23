#include <Arduino.h>
#include <TinyMPU6050.h>

MPU6050 mpu (Wire);

void setup() {
  // put your setup code here, to run once:
  mpu.Initialize();
  Serial.begin(9600);
  Serial.println("Start Calibration");
  mpu.Calibrate();
  Serial.println("Calibration complete");
}

void loop() {
  // put your main code here, to run repeatedly:
  mpu.Execute();
  Serial.println(mpu.GetAngZ());
}
