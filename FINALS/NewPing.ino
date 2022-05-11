#include <NewPing.h>    

#define trig_pin A0 
#define echo_pin A1 
#define maximum_distance 500

int distance = 0;

NewPing sonar(trig_pin, echo_pin, maximum_distance); 

void setup(){
  Serial.begin(9600);  
}

void loop(){
  Serial.print("Distance: ");
  Serial.println(distance);
  readPing();
}

void readPing(){
  distance = sonar.ping_cm();
  delay(100);
}