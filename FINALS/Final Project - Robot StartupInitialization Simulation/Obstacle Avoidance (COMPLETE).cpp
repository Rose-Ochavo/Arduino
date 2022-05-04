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
  // Serial.print("distance: ");
  // Serial.println(distance);
  // Serial.print("leftState: ");
  // Serial.println(leftState);
  // Serial.print("rightState: ");
  // Serial.println(rightState);
  // Serial.println();

  // Serial.println("moveforward"); 
  // Serial.println();

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
    // Serial.println("IBALIK NA");
    // delay(3000);

    servoPin.write(180);//155
    delay(1000);
      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);    
        leftState = pulseIn(echo_pin, HIGH);
      // Serial.print("leftState: ");
      // Serial.println(leftState);
      // delay(2000);
      // delay(2000);    

    servoPin.write(0);//35
    delay(1000);
            digitalWrite(trigger_pin, HIGH);
              delay(10);
            digitalWrite(trigger_pin, LOW);    
              rightState = pulseIn(echo_pin, HIGH);
            // Serial.print("rightState: ");
            // Serial.println(rightState);
            // delay(2000);

    servoPin.write(90);//100
    delay(1000);
  }

  while(rightState <= 1500 && leftState <= 1500 && distance <= 1500){
    // Serial.println();

    // Serial.println("Stop");
    moveStop();
    // delay(50);
      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);
        distance = pulseIn(echo_pin, HIGH);
      // delay(1000);

      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);
        leftState = pulseIn(echo_pin, HIGH);
      // delay(1000);

      digitalWrite(trigger_pin, HIGH);
        delay(10);
      digitalWrite(trigger_pin, LOW);
        rightState = pulseIn(echo_pin, HIGH);
      // delay(1000);          
  }

  if(leftState <= 5000){
    // Serial.println();
    // Serial.println("TurnRight");
    moveRight();
    delay(700);
    // delay(3000);    
  } 

  if(rightState <= 5000){
   //    Serial.println();

   // Serial.println("TurnLeft");
    moveLeft();   
    delay(50);
    // delay(3000);
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
