#include <Servo.h>

Servo servoPin;

const byte trigger_pin = A0;
const byte echo_pin = A1;
const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 8;

long distance, leftState, rightState;

void setup() {
  Serial.begin(9600);
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  servoPin.attach(3, 500, 2500);
  servoPin.write(100);//100
  delay(1000);  
}

void loop() {
    digitalWrite(trigger_pin, HIGH);
    delay(10);
    digitalWrite(trigger_pin, LOW);
    distance = pulseIn(echo_pin, HIGH);
    delay(100);
    leftState = 0;
    rightState = 0;

  if(distance > 1600){
    moveForward();          
  }
  else if(distance < 1600){
    moveStop();

    servoPin.write(180);//155
    delay(1000);
      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);    
        leftState = pulseIn(echo_pin, HIGH);

    servoPin.write(10);//35
    delay(1000);
      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);    
        rightState = pulseIn(echo_pin, HIGH);
            
    servoPin.write(100);//100
    delay(1000);
  }
  
  if(leftState > rightState){   
    moveLeft();
    delay(400);
  } 
  else if(rightState > leftState){   
    moveRight();   
    delay(400);
    rightState = 0;
    leftState = 0;    
  }
  //   else if(rightState > 2000 && leftState > 2000 && distance < 1700){   
  //   moveRight();   
  //   delay(500);   
  // }
}

void stopMotor1(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
}

void stopMotor2(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

void forwardMotor1(){
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
}

void forwardMotor2(){
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void moveForward(){
  forwardMotor1();
  forwardMotor2();
}

void moveStop() {
  stopMotor1();
  stopMotor2();
 }

void moveLeft(){
  forwardMotor1();
  stopMotor2();
 }
 
 void moveRight(){
  forwardMotor2();
  stopMotor1();
 }
