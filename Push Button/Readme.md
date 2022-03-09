<p align="center">
<img src="https://github.com/alrose102318/Arduino/blob/5a7a3f8fcd3adb9554522212b42bd2a89dd7f8c0/Push%20Button/diagram.jpg" width="800" height="500">
</p>

```
int pinButton = 8;
int LED = 2;

void setup() {
  pinMode(pinButton, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int stateButton = digitalRead(pinButton);
  if (stateButton == 1) {
    digitalWrite(LED, HIGH);
  }
  // else{
  //   digitalWrite(LED, LOW);
  // }
}
```
