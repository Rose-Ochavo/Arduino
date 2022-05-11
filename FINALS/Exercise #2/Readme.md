> Code
```
int state = 0;
int Pbutton = 8;
int led = 3;

void setup()
{
  pinMode(Pbutton, INPUT);
  pinMode(led, OUTPUT);
}

void loop()
{
  if (digitalRead(Pbutton) == HIGH) {
    if (state != 255) {
      state+=3;
      delay(30); 
    }
    analogWrite(led, state);
  }

  if (digitalRead(Pbutton) == LOW) {
    if (state != 0) {
      state-=3;
      delay(30);
    }
    analogWrite(led, state);    
  }
}
```

> Diagram
<p align="left" style="margin-left:33px"><img src="https://github.com/alrose102318/Arduino/blob/b5dc69e77f7e928ba8b01c9d317dbbeda0ea4012/FINALS/Exercise%20%232/diagram.png" /></p>
