#include <Servo.h>

int pos = 0;

Servo servo_9;

const unsigned long BLINK_DELAY = 100 ;  
unsigned long blink_time = 0 ;
bool led_on = false ;

void setup()
{
  servo_9.attach(9, 500, 2500);
  pinMode(13, OUTPUT);
}

void loop()
{
  start_blink();
  for (pos = 0; pos <= 180; pos++) {  
    servo_9.write(pos);
    
    delay(15); 
    blink(); 
  }
  stop_blink();

  delay(2000); 

  start_blink();
  for (pos = 180; pos >= 0; pos--) {    
    servo_9.write(pos);
    
    delay(15); 
    blink();
  }
  stop_blink(); 
}

void start_blink() {
  digitalWrite(13, HIGH);
  led_on = true ;
  blink_time = millis() + BLINK_DELAY ;
}

void stop_blink() {
  digitalWrite(13,LOW);
  led_on = false ;
}

void blink() {
  if ( millis() > blink_time ) {
    led_on = !led_on ;
    digitalWrite(13, led_on ? HIGH : LOW);
    blink_time = millis() + BLINK_DELAY ;
  }
}
