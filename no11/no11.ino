#include <Stepper.h>

Stepper stepper(360, 4, 5, 6, 7);
int ang_p, ang;

void setup() {
  stepper.setSpeed(30);
  
  Serial.begin(9600);

  ang_p = ang = val2ang(analogRead(0));
}

void loop() {
  ang_p = ang;
  ang = val2ang(analogRead(0));

  int ang_d = ang - ang_p;

  Serial.print(ang_p);
  Serial.print(", ");
  Serial.print(ang);
  Serial.print(", ");
  Serial.print(ang_d);
  Serial.println("");
  
  stepper.step(ang_d);
}
