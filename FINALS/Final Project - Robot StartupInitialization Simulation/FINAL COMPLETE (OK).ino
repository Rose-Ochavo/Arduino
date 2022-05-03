#include <Servo.h>

Servo servoPin;

const byte trigger_pin = A0;
const byte echo_pin = A1;

long distance;

void setup() {
  Serial.begin(9600);
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT); 
  pinMode(13, OUTPUT);

  servoPin.attach(9, 500, 2500);
  servoPin.write(90);
  delay(1000);  
}

void loop() {
  Serial.println(distance);

  digitalWrite(trigger_pin, HIGH);
  delay(10);
  digitalWrite(trigger_pin, LOW);

  distance = pulseIn(echo_pin, HIGH);
  delay(100);

  if(distance <= 300){
    digitalWrite(13, HIGH);

    servoPin.write(180);  
    delay(1000);

    servoPin.write(0);
    delay(1000);

    servoPin.write(90);
    delay(1000);
  }else{
    digitalWrite(13, LOW);
  }
}
