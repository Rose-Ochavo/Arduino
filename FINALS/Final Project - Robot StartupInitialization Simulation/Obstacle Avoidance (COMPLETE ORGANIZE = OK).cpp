#include <Servo.h>

Servo servoPin;

const byte trigger_pin = A0;
const byte echo_pin = A1;
const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 8;

int leftState = 0;
int rightState = 0;

long distance;

void setup() {
  Serial.begin(9600);
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  servoPin.attach(3, 500, 2500);
  servoPin.write(90);//100
  delay(1000);  
}

void loop() {
    digitalWrite(trigger_pin, HIGH);
    delay(10);
    digitalWrite(trigger_pin, LOW);    
    leftState = pulseIn(echo_pin, HIGH);

    digitalWrite(trigger_pin, HIGH);
    delay(10);
    digitalWrite(trigger_pin, LOW);    
    rightState = pulseIn(echo_pin, HIGH);

    digitalWrite(trigger_pin, HIGH);
    delay(10);
    digitalWrite(trigger_pin, LOW);
    distance = pulseIn(echo_pin, HIGH);
    delay(100);

      moveForward();      
      
  if(distance <= 1500){
    servoPin.write(180);//155
    delay(1000);
      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);    
        leftState = pulseIn(echo_pin, HIGH);

    servoPin.write(0);//35
    delay(1000);
      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);    
        rightState = pulseIn(echo_pin, HIGH);
            
    servoPin.write(90);//100
    delay(1000);
  }

  while(rightState <= 1500 && leftState <= 1500 && distance <= 1500){
    moveStop();

      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);
        distance = pulseIn(echo_pin, HIGH);

      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);
        leftState = pulseIn(echo_pin, HIGH);

      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);
        rightState = pulseIn(echo_pin, HIGH);
  }

  if(leftState <= 5000){   
    moveRight();
    delay(700);
  } 

  if(rightState <= 5000){   
    moveLeft();   
    delay(50);
  }
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
