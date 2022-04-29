> Code

```
#include <Servo.h>

Servo servopin;
int pos;

void setup(){
  servopin.attach(8);
}

void loop(){

  for(pos = 0; pos != 180; pos++){
    servopin.write(pos);
    delay(15);
  }
  for(pos = 180; pos != 0; pos--){
    servopin.write(pos);
    delay(15);
  }

}
```