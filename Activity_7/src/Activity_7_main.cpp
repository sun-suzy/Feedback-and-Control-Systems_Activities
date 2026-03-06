#include <Arduino.h> 
#include <Servo.h>

Servo my_motor;
int motor_pin = 9;

void setup() {
  my_motor.attach(motor_pin);
  Serial.begin(9600);
  my_motor.write(0); // Home position
  Serial.println("Arduino: Ready! Please enter a degree (0 to 180).");
}

void loop() {
  if (Serial.available() > 0) {
    int input_angle = Serial.parseInt();
    
    // Clear buffer
    while(Serial.available() > 0) { Serial.read(); }

    if (input_angle >= 0 && input_angle <= 180) {
      my_motor.write(input_angle);
      Serial.print("Great! The motor is now at ");
      Serial.print(input_angle);
      Serial.println(" degrees.");
    } else {
      Serial.print("Oops! ");
      Serial.print(input_angle);
      Serial.println(" is invalid. Use 0-180.");
    }
  }
}