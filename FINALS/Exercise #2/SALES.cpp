//GROUP OF SALES, ABALOS, OAQUIRA

int pinButton = 8;
int LED = 6;
int LED1 = 3;
int LED2 = 9;

int value = 0;

void setup() {
  pinMode (pinButton, INPUT);
  pinMode (LED, OUTPUT);
  pinMode (LED1, OUTPUT);
  pinMode (LED2, OUTPUT);
}

  void loop() {
  int stateButton = digitalRead(pinButton);

  if (stateButton == 1){
    for(int i = 0; i < 255; i++){
      analogWrite (LED, i);
      analogWrite (LED1, i);
      analogWrite (LED2, i);
      delay(20);
      value = i;
    }
  }

  if (stateButton == 0){
    for(int i = value; i > 0; i--){
      analogWrite (LED, i);
      analogWrite (LED1, i);
      analogWrite (LED2, i);
      delay(5);
      analogWrite(LED, LOW);
      analogWrite(LED1, LOW);
    }
  }
}