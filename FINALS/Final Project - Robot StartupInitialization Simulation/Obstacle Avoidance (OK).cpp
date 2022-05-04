#include <Servo.h>

Servo servoPin;

const byte trigger_pin = A0;
const byte echo_pin = A1;

int leftState = 0;
int rightState = 0;

long distance;

void setup() {
  Serial.begin(9600);
  pinMode(echo_pin, INPUT);
  pinMode(trigger_pin, OUTPUT); 

  servoPin.attach(9, 500, 2500);
  servoPin.write(90);//100
  delay(100);  
}

void loop() {
  Serial.print("distance: ");
  Serial.println(distance);
  Serial.print("leftState: ");
  Serial.println(leftState);
  Serial.print("rightState: ");
  Serial.println(rightState);
  Serial.println();

  Serial.println("moveforward"); 
  Serial.println();

          digitalWrite(trigger_pin, HIGH);
          delay(10);
          digitalWrite(trigger_pin, LOW);    
          leftState = pulseIn(echo_pin, HIGH);

          digitalWrite(trigger_pin, HIGH);
          delay(10);
          digitalWrite(trigger_pin, LOW);    
          rightState = pulseIn(echo_pin, HIGH);

          digitalWrite(trigger_pin, HIGH);
          delay(10);
          digitalWrite(trigger_pin, LOW);
          distance = pulseIn(echo_pin, HIGH);
          delay(1000);

  if(distance <= 5000){
    Serial.println("IBALIK NA");
    delay(3000);

    servoPin.write(180);//155
    delay(1000);

            digitalWrite(trigger_pin, HIGH);
            delay(10);
            digitalWrite(trigger_pin, LOW);    
            leftState = pulseIn(echo_pin, HIGH);
            Serial.print("leftState: ");
            Serial.println(leftState);
            delay(2000);
            delay(2000);    

    servoPin.write(0);//35
    delay(1000);
            digitalWrite(trigger_pin, HIGH);
            delay(10);
            digitalWrite(trigger_pin, LOW);    
            rightState = pulseIn(echo_pin, HIGH);
            Serial.print("rightState: ");
            Serial.println(rightState);
            delay(2000);

    servoPin.write(90);//100
    delay(1000);
  }

  while(rightState <= 5000 && leftState <= 5000 && distance <= 5000){
      Serial.println();

   Serial.println("Stop");
    delay(50);
          digitalWrite(trigger_pin, HIGH);
          delay(10);
          digitalWrite(trigger_pin, LOW);
          distance = pulseIn(echo_pin, HIGH);
          delay(1000);

          digitalWrite(trigger_pin, HIGH);
          delay(10);
          digitalWrite(trigger_pin, LOW);
          leftState = pulseIn(echo_pin, HIGH);
          delay(1000);

          digitalWrite(trigger_pin, HIGH);
          delay(10);
          digitalWrite(trigger_pin, LOW);
          rightState = pulseIn(echo_pin, HIGH);
          delay(1000);          
  }

    if(leftState <= 5000){
      Serial.println();
      Serial.println("TurnRight");
    delay(50);
    delay(3000);    

  } 
   if(rightState <= 5000){
      Serial.println();

   Serial.println("TurnLeft");
    delay(50);
    delay(3000);
  }
}