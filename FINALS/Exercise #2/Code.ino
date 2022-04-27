int led_pin = 6;
int P_button = 3;

void setup(){
  pinMode(led_pin, OUTPUT);
  pinMode(P_button, INPUT);
}

void loop(){
  int state = 0;

  if (digitalRead(P_button) == HIGH){
    for(int i = state; i < 255; i++){
      analogWrite(led_pin, i);
      state++;
      delay(5);
      break;
    }
  }

  if (digitalRead(P_button) == LOW){
    for(int i = state; i > 0; i--){
      analogWrite(led_pin, i);
      state--;
      delay(5);
      break;      
    }
  }
}
