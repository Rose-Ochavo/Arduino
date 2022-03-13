//L298n
const int ena = 5;
const int in1 = 6;
const int in2 = 7;
const int in3 = 8;
const int in4 = 9;
const int enb = 10;

//IR
const int LeftMost = A0;
const int Left1 = A1;
const int Middle = A2;
const int Right2 = A3;
const int RightMost = A4;

int LMost = 0;
int L1 = 0;
int Mid = 0;
int R2 = 0;
int RMost = 0;

void setup() {
	pinMode(LeftMost, INPUT);
	pinMode(Left1, INPUT);
	pinMode(Middle, INPUT);
	pinMode(Right2, INPUT);
	pinMode(RightMost, INPUT);

	pinMode(ena, OUTPUT);
	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(enb, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
}
// black == 0

// (digitalRead(LMost == 0)) && (digitalRead(L1 == 0)) && (digitalRead(Mid == 0)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))

void loop() {
	// Reading values
	LMost = LeftMost;
	L1 = Left1;
	Mid = Middle;
	R2 = Right2;
	RMost = RightMost;

	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 1)) && (digitalRead(Mid == 0)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))) {//ForwardMaxSpeed
		Maxforward();
	}
	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 1)) && (digitalRead(Mid == 1)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))) {//ForwardRun
		Maxforward();
	}

	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 1)) && (digitalRead(Mid == 1)) && (digitalRead(R2 == 0)) && (digitalRead(RMost == 1))) {//TurnRight
		TRight();
	}
	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 1)) && (digitalRead(Mid == 1)) && (digitalRead(R2 == 0)) && (digitalRead(RMost == 0))) {//HardRight
		HRight();
	}
	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 1)) && (digitalRead(Mid == 0)) && (digitalRead(R2 == 0)) && (digitalRead(RMost == 0))) {//HardRight
		HRight();
	}

	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 0)) && (digitalRead(Mid == 1)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))) {//TurnLeft
		TLeft();
	}
	if((digitalRead(LMost == 0)) && (digitalRead(L1 == 0)) && (digitalRead(Mid == 1)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))) {//HardLeft
		HLeft();
	}
	if((digitalRead(LMost == 0)) && (digitalRead(L1 == 0)) && (digitalRead(Mid == 0)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))) {//HardLeft
		HLeft();
	}
	if((digitalRead(LMost == 0)) && (digitalRead(L1 == 0)) && (digitalRead(Mid == 0)) && (digitalRead(R2 == 0)) && (digitalRead(RMost == 0))) {//Stop
		Stop();
	}
}

void Maxforward(){
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
	analogWrite(ena, 255);
  
 	digitalWrite(in3,LOW);
	digitalWrite(in4,HIGH);
	analogWrite(enb, 255);
}
void Forward(){
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
	analogWrite(ena, 200);
	
	digitalWrite(in3,LOW);
	digitalWrite(in4,HIGH);
	analogWrite(enb, 200);
}
void TRight(){
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
	analogWrite(ena, 200);

	digitalWrite(in3,LOW);
	digitalWrite(in4,HIGH);
	analogWrite(enb, 255);
}
void HRight(){
	digitalWrite(in1,LOW);
	digitalWrite(in2,LOW);
	analogWrite(ena, 0);

	digitalWrite(in3,LOW);
	digitalWrite(in4,HIGH);
	analogWrite(enb, 255);
}
void TLeft(){
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
	analogWrite(ena, 255);

	digitalWrite(in3,LOW);
	digitalWrite(in4,HIGH);
	analogWrite(enb, 200);
}
void HLeft(){
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
	analogWrite(ena, 255);

	digitalWrite(in3,LOW);
	digitalWrite(in4,LOW);
	analogWrite(enb, 0);
}
void Stop(){
	digitalWrite(in1,LOW);
	digitalWrite(in2,LOW);
	analogWrite(ena, 0);
	digitalWrite(in3,LOW);
	digitalWrite(in4,LOW);
	analogWrite(enb, 0);

}