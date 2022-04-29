> Code

```
//sensor Pins;
const int sensorLeftMost = 2;
const int s1 = 3;
const int sensorMiddle = 13;
const int s2 = 4;
const int sensorRightMost = 5;

//L298n Pins
const int in1 = 11;
const int in2 = 10;
const int in3 = 9;
const int in4 = 8;

int IRvalueLeftMost = 0;
int IRvalue2 = 0;
int IRvalueMiddle = 0;
int IRvalue3 = 0;
int IRvalueRightMost = 0;

void setup(){
  pinMode(sensorLeftMost,INPUT);
  pinMode(s1,INPUT);
  pinMode(sensorMiddle,INPUT);
  pinMode(s2,INPUT);
  pinMode(sensorRightMost,INPUT);

  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
}

void loop(){

  //Reading values
  IRvalueLeftMost = digitalRead(sensorLeftMost);
  IRvalue2 = digitalRead(s1);
  IRvalueMiddle = digitalRead(sensorMiddle);
  IRvalue3 = digitalRead(s2);
  IRvalueRightMost = digitalRead(sensorRightMost);

  if (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==0 && IRvalue3==1 && IRvalueRightMost==1){// run forward
    moveForward();
  }
  if (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) {// run forward
    moveForward();
  }

  //Instance to move right
  else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==0 && IRvalueRightMost==1) {//nudge to the right a little bit
    moveRight();
  }
  else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==0 && IRvalue3==0 && IRvalueRightMost==1) {//nudge to the right
    moveRight();
  }
  else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==0 && IRvalueRightMost==0) {//turn right sharply
    sharpRightTurn();
  }
  else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==0) {//turn right sharply
    sharpRightTurn();
  }

  //Instace to move left
  else if  (IRvalueLeftMost==1 && IRvalue2==0 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) {//nudge to the left a little bit
    moveLeft();
  }
  else if  (IRvalueLeftMost==1 && IRvalue2==0 && IRvalueMiddle==0 && IRvalue3==1 && IRvalueRightMost==1) {//nudge to the left
    moveLeft();
  }
  else if  (IRvalueLeftMost==0 && IRvalue2==0 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) {//turn right sharply 
    sharpLeftTurn();
  }
  else if  (IRvalueLeftMost==0 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) {//turn right sharply 
    sharpLeftTurn();
  }
  else if (IRvalueLeftMost==0 && IRvalue2==0 && IRvalueMiddle==0 && IRvalue3==0 && IRvalueRightMost==0) {// turn back
    //Option 1
    moveStop();// stop both motor // Optional

    //turn back 180 degrees
    stopMotor1();//stop left motor
    forwardMotor2();// run motor2 to turn
    delay(1000);// set the delay time to turn // 1000msec == 1sec


    /* Option 2
    moveStop();// stop both motor // Optional

    //turn 180 degrees
    reverseMotor1();//reverse left motor
    forwardMotor2();// forward right to turn
    delay(1000);// set the delay time to turn // 1000msec == 1sec
    */

  }
}

void sharpLeftTurn(){
  int middleSensorValue, sensor3Value, sensorRight;

  middleSensorValue = digitalRead(sensorMiddle);
  sensor3Value = digitalRead(s2);
  sensorRight = digitalRead(sensorRightMost);

  while (middleSensorValue == 1 && sensor3Value==1 && sensorRight==1){
    forwardMotor1();
    stopMotor2();

    middleSensorValue = digitalRead(sensorMiddle);
    sensor3Value = digitalRead(s2);
    sensorRight = digitalRead(sensorRightMost);
  }
  moveStop();
  forwardMotor2();
  delay(30);
  moveForward();
}

void sharpRightTurn(){
  int middleSensorValue, sensor1Value, sensorLeft;

  middleSensorValue = digitalRead(sensorMiddle);
  sensor1Value = digitalRead(s1);
  sensorLeft = digitalRead(sensorLeftMost);

  while (middleSensorValue == 1 && sensor1Value==1 && sensorLeft==1){
    forwardMotor2();
    stopMotor1();

    middleSensorValue = digitalRead(sensorMiddle);
    sensor1Value = digitalRead(s1);
    sensorLeft = digitalRead(sensorLeftMost);
  }
  moveStop();
  forwardMotor1();
  delay(30);
  moveForward();
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

void reverseMotor1(){
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
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
```