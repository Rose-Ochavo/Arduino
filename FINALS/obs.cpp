#include <Servo.h>

Servo servoPin;

const byte trigger_pin = A0;
const byte echo_pin = A1;

const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 8;

long distance;

int leftState = 0;
int rightState = 0;

void setup() {
  Serial.begin(9600);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT); 
  pinMode(13, OUTPUT);

  servoPin.attach(3, 500, 2500);
  servoPin.write(100);//or 90
  delay(1000);    
}

void loop() {
  Serial.println(distance);

  digitalWrite(trigger_pin, HIGH);
  delay(10);
  digitalWrite(trigger_pin, LOW);

  distance = pulseIn(echo_pin, HIGH);
  delay(100);

  moveForward();

  if(distance <= 1000){
    moveStop();

    digitalWrite(13, HIGH);

    servoPin.write(180);//or 180  
    delay(1000);

    digitalWrite(trigger_pin, HIGH);
    delay(10);
    leftState = pulseIn(echo_pin, HIGH);


    servoPin.write(0);//or 0  
    delay(1000);
    digitalWrite(trigger_pin, HIGH);
    delay(10);
    rightState = pulseIn(echo_pin, HIGH);

    servoPin.write(100);//or 90
    delay(1000);

  }else{
    digitalWrite(13, LOW);
  }

  if(leftState <= 1000){
    moveRight();
    delay(700);
    moveStop();
    delay(50);

  }
  else if(rightState <= 1000){
    moveLeft();
    delay(700);
    moveStop();
    delay(50);
  }
  // if(leftState <= 1000 && rightState <= 1000){
  //   moveForward();
  // }
  // else{
  //   moveForward();
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
