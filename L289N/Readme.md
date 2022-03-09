<p align="center">
<img src="https://github.com/alrose102318/Arduino/blob/3b0dee53f2a429587036da79ea6b1cc9cabb9a02/L289N/1%20.jpg" width="800" height="500">
</p>

```
const int in1 = 2;
const int in2 = 3;
const int in3 = 4;
const int in4 = 5;

void setup() {
  delay(2000);
}

void loop() {
  forwardRun();
  delay(5000);
  
  backwardRun();
  delay(5000);
}

void backwardRun() {
  digitalWrite(in1 , HIGH);
  digitalWrite(in2 , LOW);
  digitalWrite(in3 , HIGH);
  digitalWrite(in4 , LOW);
}

void forwardRun() {
  digitalWrite(in1 , LOW);
  digitalWrite(in2 , HIGH);
  digitalWrite(in3 , LOW);
  digitalWrite(in4 , HIGH);
}
```
