```
int led_pin = 6;
int pot_pin = A0;
int output;
int led_value;

void setup() {
  pinMode(led_pin, OUTPUT);
}

void loop() {
  output = analogRead(pot_pin);
  led_value = map(output, 0, 1023, 0, 255);
  analogWrite(led_pin, led_value);
  delay(1);
}

```