#include <Stepper.h>

//Define motor/driver inputs
#define STEPPER11 7
#define STEPPER12 6
#define STEPPER13 5
#define STEPPER14 4
const int STEPS_PER_REV = 2048;  // For 28BYJ-48 motors, adjust as per your motor's specs

//Create Motor object
Stepper motor1(STEPS_PER_REV, STEPPER11, STEPPER13, STEPPER12, STEPPER14);  // Pins for Motor 1

//Set up runs only once, immediately when arduino is powered
void setup() {
 motor1.setSpeed(15); //set speed of motor
}

//Loop continuously runs as long as arduino is powered
void loop() {
  motor1.step(STEPS_PER_REV); //Move motor one direction
  delay(1000);  //wait 1 second
  motor1.step(-STEPS_PER_REV);  //Move motor other direction
  delay(1000);  //wait 1 secon

  
  /*
  // Generate random values for direction and speed
  int randomDirection1 = random(0, 2);  // Random direction for Motor 1 (0 = clockwise, 1 = counterclockwise)
  int randomSteps1 = random(50, 200);   // Random number of steps for Motor 1
  int randomSpeed1 = random(minSpeed, maxSpeed);  // Random speed for Motor 1
  
  int randomDirection2 = random(0, 2);  // Random direction for Motor 2 (0 = clockwise, 1 = counterclockwise)
  int randomSteps2 = random(50, 200);   // Random number of steps for Motor 2
  int randomSpeed2 = random(minSpeed, maxSpeed);  // Random speed for Motor 2

  // Set the new random speed for both motors
  motor1.setSpeed(randomSpeed1);
  motor2.setSpeed(randomSpeed2);

  // Move Motor 1 based on the random direction
  if (randomDirection1 == 0) {
    motor1.step(randomSteps1);  // Move forward (clockwise)
  } else {
    motor1.step(-randomSteps1); // Move backward (counterclockwise)
  }

  // Move Motor 2 based on the random direction
  if (randomDirection2 == 0) {
    motor2.step(randomSteps2);  // Move forward (clockwise)
  } else {
    motor2.step(-randomSteps2); // Move backward (counterclockwise)
  }

  // Add a small delay between moves
  delay(500);*/


}
