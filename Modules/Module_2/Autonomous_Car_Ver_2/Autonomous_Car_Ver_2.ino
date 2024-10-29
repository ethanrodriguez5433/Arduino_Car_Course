//Define motor/driver inputs
#define PIN1 10
#define PIN2 11
#define PIN3 6
#define PIN4 7

#define trigPin 9
#define echoPin 8

//Set up runs only once, immediately when arduino is powered
void setup() 
{
  Serial.begin(9600);          // Initialize serial communication at 9600 bps
  pinMode(trigPin, OUTPUT);     // Set trigPin as an output
  pinMode(echoPin, INPUT);      // Set echoPin as an input
  
  pinMode(PIN1, OUTPUT);  //PIN 1 FOR MOTOR 1
  pinMode(PIN2, OUTPUT);  //PIN 2 FOR MOTOR 1
  pinMode(PIN3, OUTPUT);  //PIN 3 FOR MOTOR 2
  pinMode(PIN4, OUTPUT);  //PIN 4 FOR MOTOR 2
}

void loop() {
  long duration, inches, cm;

  // Trigger the ultrasonic burst
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the time it takes for the echo to return
  duration = pulseIn(echoPin, HIGH);

  // Convert duration to centimeters
  cm = microsecondsToCentimeters(duration);

  // Print the distance to the Serial Monitor
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();

  if(cm <= 10)
    moveLeft();
  else
    moveForward();

}

// Function to convert microseconds to centimeters
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;   // Speed of sound in air (cm per microsecond)
}

void moveForward()
{
  //set pins 1 & 4 to low and 2 & 3 to high
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN2, HIGH);
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, HIGH);
  delay(1000);
}

void moveBackward()
{
  //set pins 2 & 3 to low and 1 & 4 to high
  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, HIGH);
  digitalWrite(PIN4, LOW);
  delay(1000);
}

void moveLeft()
{
  //set pins 1 & 3 to high and 2 & 4 to low 
  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, HIGH);
  delay(1000);
}

void moveRight()
{
  //set pins 2 & 4 to high and 1 & 3 to low
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN2, HIGH);
  digitalWrite(PIN3, HIGH);
  digitalWrite(PIN4, LOW);
  delay(1000);
}
