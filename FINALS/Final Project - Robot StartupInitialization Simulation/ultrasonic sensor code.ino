const byte trigger_pin = A1;
const byte echo_pin = A0;

long duration;

void setup() {
  Serial.begin(9600);
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT);  
}

void loop() {
  
  digitalWrite(trigger_pin, HIGH);
  delay(10);
  digitalWrite(trigger_pin, LOW);

  duration = pulseIn(echo_pin, HIGH);

  Serial.println(duration);
  delay(100);
}