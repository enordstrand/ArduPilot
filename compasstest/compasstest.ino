#include <Wire.h>
#include <MechaQMC5883.h>

MechaQMC5883 qmc;

void setup() {
  Wire.begin();
  Serial.begin(9600);
  qmc.init();
  //qmc.setMode(Mode_Continuous,ODR_200Hz,RNG_2G,OSR_256);
}

void loop() {
  int x,y,z;
  qmc.read(&x,&y,&z);

  int az = 90 - atan2(y, x) * 180 / M_PI;
  Serial.print("deg: ");
  Serial.print(az);

 // Serial.print("x: ");
 // Serial.print(x);
 // Serial.print(" y: ");
 // Serial.print(y);
 // Serial.print(" z: ");
 // Serial.print(z);
  Serial.println();
  delay(100);
}
