//L298n
const int in1 = 6;
const int in2 = 7;
const int in3 = 8;
const int in4 = 9;

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

	pinMode(in1, OUTPUT);
	pinMode(in2, OUTPUT);
	pinMode(in3, OUTPUT);
	pinMode(in4, OUTPUT);
}
// blacksurface == 0

void loop() {
	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 1)) && (digitalRead(Mid == 0)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))) {
		Maxforward();
	}

	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 1)) && (digitalRead(Mid == 1)) && (digitalRead(R2 == 0)) && (digitalRead(RMost == 1))) {
		TRight();
	}
	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 1)) && (digitalRead(Mid == 1)) && (digitalRead(R2 == 0)) && (digitalRead(RMost == 0))) {
		TRight();
	}
	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 1)) && (digitalRead(Mid == 0)) && (digitalRead(R2 == 0)) && (digitalRead(RMost == 0))) {
		TRight();
	}

	if((digitalRead(LMost == 1)) && (digitalRead(L1 == 0)) && (digitalRead(Mid == 1)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))) {
		TLeft();
	}
	if((digitalRead(LMost == 0)) && (digitalRead(L1 == 0)) && (digitalRead(Mid == 1)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))) {
		TLeft();
	}
	if((digitalRead(LMost == 0)) && (digitalRead(L1 == 0)) && (digitalRead(Mid == 0)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))) {
		TLeft();
	}
	if((digitalRead(LMost == 0)) && (digitalRead(L1 == 0)) && (digitalRead(Mid == 0)) && (digitalRead(R2 == 0)) && (digitalRead(RMost == 0))) {//Stop
		Stop();
	}

        if((digitalRead(LMost == 1)) && (digitalRead(L1 == 1)) && (digitalRead(Mid == 1)) && (digitalRead(R2 == 1)) && (digitalRead(RMost == 1))) {
		Stop();
	}
}

void Maxforward(){
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);
  
 	digitalWrite(in3,LOW);
	digitalWrite(in4,HIGH);
}
void TRight(){
	digitalWrite(in1,LOW);
	digitalWrite(in2,LOW);

	digitalWrite(in3,LOW);
	digitalWrite(in4,HIGH);
}

void TLeft(){
	digitalWrite(in1,HIGH);
	digitalWrite(in2,LOW);

	digitalWrite(in3,LOW);
	digitalWrite(in4,LOW);
}

void Stop(){
	digitalWrite(in1,LOW);
	digitalWrite(in2,LOW);

	digitalWrite(in3,LOW);
	digitalWrite(in4,LOW);

}
