#include <Servo.h>

Servo servoPin;

void setup() {
  servoPin.attach(9, 500, 2500);
  servoPin.write(90);
  delay(1000);  
}

void loop() {
  servoPin.write(180);    
  delay(1000);

  servoPin.write(0);
  delay(1000);

  servoPin.write(90);
  delay(1000);
}
