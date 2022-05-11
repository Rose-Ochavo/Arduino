> Code
```
//sensor pins;
const int sensorLeftMost = 2;
const int s1 = 3;
const int sensorMiddle = 13;
const int s2 = 4;
const int sensorRightMost = 5;

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
  //Serial.begin(9600);
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

  // Reading values
  IRvalueLeftMost = digitalRead(sensorLeftMost);
  IRvalue2 = digitalRead(s1);
  IRvalueMiddle = digitalRead(sensorMiddle);
  IRvalue3 = digitalRead(s2);
  IRvalueRightMost = digitalRead(sensorRightMost);

   if (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) // stop
 {
  moveStop();
  delay(1000);
  moveLeft();
  delay(1600);
 }
 else if (IRvalueLeftMost==0 && IRvalue2==0 && IRvalueMiddle==0 && IRvalue3==0 && IRvalueRightMost==0) // stop
 {
  moveStop();
 }
 else if (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==0 && IRvalue3==1 && IRvalueRightMost==1) // run forward
 {
  moveForward();
 }
 if (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) // run forward
 {
  moveForward();
 }
 //instance to move right
 else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==0 && IRvalueRightMost==1) //nudge to the right a little bit
 {
  moveRight();
 }
 else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==0 && IRvalue3==0 && IRvalueRightMost==1) //nudge to the right
 {
  moveRight();
 }
 else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==0 && IRvalueRightMost==0) //turn right sharply
 {
  //moveRight();
  sharpRightTurn();
 }
  else if  (IRvalueLeftMost==1 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==0) //turn right sharply //nudge to the right a little harder
 {
  sharpRightTurn();

 }
 //instace to move left
 else if  (IRvalueLeftMost==1 && IRvalue2==0 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) //nudge to the left a little bit
 {
  moveLeft();
 }
 else if  (IRvalueLeftMost==1 && IRvalue2==0 && IRvalueMiddle==0 && IRvalue3==1 && IRvalueRightMost==1) //nudge to the left
 {
  moveLeft();
 }
 else if  (IRvalueLeftMost==0 && IRvalue2==0 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) //turn right sharply //nudge to the right a little harder
 {
  //moveLeft();
  sharpLeftTurn();
 }
  else if  (IRvalueLeftMost==0 && IRvalue2==1 && IRvalueMiddle==1 && IRvalue3==1 && IRvalueRightMost==1) //turn right sharply //nudge to the right a little harder
 {
  sharpLeftTurn();
 }
  //delay(3000);
}

  void sharpLeftTurn(){
  int middleSensorValue, sensor3Value, sensorRight;

  middleSensorValue = digitalRead(sensorMiddle);
  sensor3Value = digitalRead(s2);
  sensorRight = digitalRead(sensorRightMost);

  //reverseMotor2();
  while (middleSensorValue == 1 && sensor3Value==1 && sensorRight==1){
    forwardMotor1();
    //reverseMotor2(); //try this
    stopMotor2();
    middleSensorValue = digitalRead(sensorMiddle);
    sensor3Value = digitalRead(s2);
    sensorRight = digitalRead(sensorRightMost);
    //delay(200);
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

  //reverseMotor1();
  while (middleSensorValue == 1 && sensor1Value==1 && sensorLeft==1){
  forwardMotor2();
  //reverseMotor1();
  stopMotor1();

  middleSensorValue = digitalRead(sensorMiddle);
  sensor1Value = digitalRead(s1);
  sensorLeft = digitalRead(sensorLeftMost);
  //delay(200);
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
