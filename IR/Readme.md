<p align="center">
<img src="https://github.com/alrose102318/Arduino/blob/85566c54465145e10427969d50c162e8a678c4c6/IR/3%20.jpg" width="800" height="500">
</p>

```
const int sensorLeftMost = 2;
const int s1 = 3;
const int sensorMiddle = 13;
const int s2 = 4;
const int sensorRightMost = 5;

int IRvalueLeftMost = 0; 
int IRvalue2 = 0; 
int IRvalueMiddle = 0; 
int IRvalue3 = 0; 
int IRvalueRightMost = 0; 

void setup() {
  Serial.begin(9600); 
  pinMode(sensorLeftMost,INPUT);
  pinMode(s1,INPUT);
  pinMode(sensorMiddle,INPUT);
  pinMode(s2,INPUT);
  pinMode(sensorRightMost,INPUT);

  // pinMode(in1, OUTPUT);
  // pinMode(in2, OUTPUT);
  // pinMode(in3, OUTPUT);
  // pinMode(in4, OUTPUT);

  // pinMode(enA, OUTPUT);
  // pinMode(enB, OUTPUT);

  // delay(2000);
  // forwardRun();
}
void loop() {
  IRvalueLeftMost = digitalRead(sensorLeftMost);
  IRvalue2 = digitalRead(s1);
  IRvalueMiddle = digitalRead(sensorMiddle);
  IRvalue3 = digitalRead(s2);
  IRvalueRightMost = digitalRead(sensorRightMost);

  Serial.print("Digital Reading=");
  Serial.print(IRvalueLeftMost);
  Serial.print(IRvalue2);
  Serial.print(IRvalueMiddle);
  Serial.print(IRvalue3);
  Serial.println(IRvalueRightMost);
  Serial.println("");
  delay(2000);
}
```
