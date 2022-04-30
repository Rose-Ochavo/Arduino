#include <Servo.h>

const int pingPin = 7;
int pos;

Servo servopin;

void setup() {
  servopin.attach(9, 500, 2500);  
    for (pos = 0; pos <= 90; pos++) {
      digitalWrite(13, LOW);
      servopin.write(pos);    
      delay(10);
    }

  Serial.begin(9600);

  pinMode(13, OUTPUT);
  pinMode(A0, OUTPUT);

}

void loop() {

  long duration, cm;

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, HIGH);

  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  if (cm > 100){

    digitalWrite(13, LOW);
    
    for (pos = 90; pos <= 180; pos++) {      
      servopin.write(pos);
      // digitalWrite(A0, HIGH);
      delay(15);
    }  
    for (pos = 180; pos >= 0; pos--) {      
      servopin.write(pos);
      delay(15);
      // digitalWrite(A0, LOW);  
    }
    for (pos = 0; pos <= 90; pos++) {      
      servopin.write(pos);
      // digitalWrite(A0, HIGH);
      delay(15);
    }
  }
  else{
    digitalWrite(13, HIGH);    
  }
}

long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;
}

void blink() {
  digitalWrite(A0, HIGH);
  delay(100); 
  digitalWrite(A0, LOW);
  delay(100);
}