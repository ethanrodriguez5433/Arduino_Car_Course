#define trigPin 7
#define echoPin 8

void setup() {
  Serial.begin(9600);          // Initialize serial communication at 9600 bps
  pinMode(trigPin, OUTPUT);     // Set trigPin as an output
  pinMode(echoPin, INPUT);      // Set echoPin as an input
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

  // Convert duration to inches and centimeters
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);

  // Print the distance to the Serial Monitor
  Serial.print(inches);
  Serial.print(" in, ");
  Serial.print(cm);
  Serial.print(" cm");
  Serial.println();

  delay(100);  // Short delay before repeating the loop
}

// Function to convert microseconds to inches
long microsecondsToInches(long microseconds) {
  return microseconds / 74 / 2;   // Speed of sound in air (inches per microsecond)
}

// Function to convert microseconds to centimeters
long microsecondsToCentimeters(long microseconds) {
  return microseconds / 29 / 2;   // Speed of sound in air (cm per microsecond)
}

