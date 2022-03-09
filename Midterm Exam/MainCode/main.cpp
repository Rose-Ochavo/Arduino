const int ena = 5;
const int in1 = 6;
const int in2 = 7;
const int in3 = 8;
const int in4 = 9;
const int enb = 10;

const int LMost = 2;
const int L1 = 3;
const int Mid = 13;
const int R2 = 4;
const int RMost = 5;

void setup() {
	pinMode(LMost, INPUT);
	pinMode(L1, INPUT);
	pinMode(Mid, INPUT);
	pinMode(R2, INPUT);
	pinMode(RMost, INPUT);


	pinMode(ena, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(enb, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
}

void loop() {
	if(digitalRead(Mid == 0)) {//ForwardMaxSpeed
		Maxforward();
	}

	if((digitalRead(L1) == 1) && (digitalRead(R2) == 1)) {//ForwardRun
		Forward();
	}
	if((digitalRead(L1) == 0) && (digitalRead(R2) == 1)) {//TurnRight
		TRight();
	}
	if((digitalRead(LMost) == 0) && (digitalRead(R2) == 1)){//HardRight
		HRight();
	}
	if((digitalRead(L1) == 1) && (digitalRead(R2) == 0)){//TurnLeft
		TLeft();
	}
	if((digitalRead(L1) == 1) && (digitalRead(RMost) == 0))//HardLeft
		HLeft();
}

void Maxforward(){
	digitalWrite(in1,HIGH);
  	digitalWrite(in2,LOW);
  	analogWrite(ena, 255);
  
 	digitalWrite(in3,HIGH);
  	digitalWrite(in4,LOW);
  	analogWrite(enb, 255);
}
void Forward(){
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
	analogWrite(ena, 127);
	
	digitalWrite(in3,HIGH);
	digitalWrite(in4,LOW);
	analogWrite(enb, 127);
}
void TRight(){
	digitalWrite(in3,HIGH);
	digitalWrite(in4,LOW);
	analogWrite(enb, 127);
}
void HRight(){
	digitalWrite(in3,HIGH);
  	digitalWrite(in4,LOW);
  	analogWrite(enb, 255);
}
void TLeft(){
	digitalWrite(in1,HIGH);
  	digitalWrite(in2,LOW);
  	analogWrite(ena, 127);
}
void HLeft(){
	digitalWrite(in1,HIGH);
 	digitalWrite(in2,LOW);
  	analogWrite(ena, 255);
}

// END OF CODE



	//MOTOR_A CLOCKWISE MAX SPEED
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, 255);
  
  //MOTOR_B CLOCKWISE MAX SPEED
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, 255);
  delay(2000);
  
  //STOP
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  delay(2000);

  // //MOTOR_A COUNTERCLOCKWISE MAX SPEED
  // digitalWrite(in1,LOW);
  // digitalWrite(in2,HIGH);
  // analogWrite(ena, 255);

  // //MOTOR_B COUNTERCLOCKWISE MAX SPEED
  // digitalWrite(in3,LOW);
  // digitalWrite(in4,HIGH);
  // analogWrite(enb, 255);
 
  // delay(2000);

  //MOTOR_A CLOCKWISE HALF SPEED 
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  analogWrite(ena, 127);
  
  //MOTOR_B CLOCKWISE HALF SPEED
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  analogWrite(enb, 127);
  delay(2000);

  // //MOTOR_A COUNTERCLOCKWISE HALF SPEED
  // digitalWrite(in1,LOW);
  // digitalWrite(in2,HIGH);
  // analogWrite(ena, 127);

  // //MOTOR_B COUNTERCLOCKWISE HALF SPEED
  // digitalWrite(in3,LOW);
  // digitalWrite(in4,HIGH);
  // analogWrite(enb, 127);
 
  // delay(2000);


void backwardRun() {
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
}