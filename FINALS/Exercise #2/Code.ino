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
      state++;
      delay(30); 
    }
    analogWrite(led, state);
  }

  if (digitalRead(Pbutton) == LOW) {
    if (state != 0) {
      state--;
      delay(30);
    }
    analogWrite(led, state);    
  }
}
