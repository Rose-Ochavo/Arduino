<p align="center">
<img src="https://github.com/alrose102318/Arduino/blob/0e10c2db3a7de3cfd0e525d633dec6453056e594/Midterm%20Exam/MainCode/main%20diagram.jpg" width="800" height="500">
</p>



```
//L298n
const int ena = 5;
const int in1 = 6;
const int in2 = 7;
const int in3 = 8;
const int in4 = 9;
const int enb = 10;

//IR
const int LMost = A0;
const int L1 = A1;
const int Mid = A2;
const int R2 = A3;
const int RMost = A4;

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
	if((digitalRead(LMost) == 0) && (digitalRead(R2) == 1)) {//HardRight
		HRight();
	}
	if((digitalRead(L1) == 1) && (digitalRead(R2) == 0)) {//TurnLeft
		TLeft();
	}
	if((digitalRead(L1) == 1) && (digitalRead(RMost) == 0)) {//HardLeft
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
void Stop(){
	digitalWrite(in1,LOW);
	digitalWrite(in2,LOW);
	digitalWrite(in3,LOW);
	digitalWrite(in4,LOW);
}
```
