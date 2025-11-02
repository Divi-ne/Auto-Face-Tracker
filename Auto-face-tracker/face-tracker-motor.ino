#include <Stepper.h>

#define STEPS 2048  // steps per revolution for 28BYJ-48 motor
Stepper stepper(STEPS, 8, 10, 9, 11);  // IN1-IN4 connected to pins 8, 9, 10, 11

char command;

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(10); // RPM
}

void loop() {
  if (Serial.available() > 0) {
    command = Serial.read();

    if (command == 'L') {
      stepper.step(-10); // Rotate left
    }
    else if (command == 'R') {
      stepper.step(10);  // Rotate right
    }
    else if (command == 'S') {
      // Stop (do nothing)
    }
  }
}
