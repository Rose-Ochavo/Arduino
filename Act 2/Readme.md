```
/* Blinker code - turns an LED on for one second, then off for one second, repeatedly.
  In this activity the output is attached to digital pin 13 */
// assigns a name called “LED_PIN” to pin 13
  
#define LED_PIN 13
// define pot to A0 (Analog pin 0)
#define POT 0
// initialize potValue to 0
int potValue = 0;
// the setup function runs once when you press reset or power the board
void setup() {
// initialize digital pin 13 as an output.
  pinMode(LED_PIN, OUTPUT);
}
// the loop function runs over and over again forever
void loop() {
  potValue = analogRead(POT); // read POT value
  digitalWrite(LED_PIN, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(potValue); // wait based on pot value
  digitalWrite(LED_PIN, LOW); // turn the LED off by making the voltage LOW
  delay(potValue); // wait based on pot value
}

```