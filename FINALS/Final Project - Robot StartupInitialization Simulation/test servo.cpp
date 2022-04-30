#include <Servo.h>

int pos;
Servo servopin;

void setup()
{
  servopin.attach(9);
}

void loop()
{
  for (pos = 0; pos <= 180; pos++) {
    servopin.write(pos);
    
    delay(15);
  }
  for (pos = 180; pos >= 0; pos--) {    
    servopin.write(pos);
    
    delay(15); 
  }
}