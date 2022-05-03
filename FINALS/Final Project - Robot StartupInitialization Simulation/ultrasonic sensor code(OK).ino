const byte trigger_pin = A1;
const byte echo_pin = A0;

long distance;

void setup() {
  Serial.begin(9600);
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT);  
}

void loop() {
  
  digitalWrite(trigger_pin, HIGH);
  delay(10);
  digitalWrite(trigger_pin, LOW);

  distance = pulseIn(echo_pin, HIGH);

  Serial.println(distance);
  delay(100);
}
