#define PIN1 10
#define PIN2 11
#define PIN3 6
#define PIN4 7
void setup() {
  pinMode(PIN1, OUTPUT);  //PIN 1 FOR MOTOR 1
  pinMode(PIN2, OUTPUT);  //PIN 2 FOR MOTOR 1
  pinMode(PIN3, OUTPUT);  //PIN 3 FOR MOTOR 2
  pinMode(PIN4, OUTPUT);  //PIN 4 FOR MOTOR 2
}

void loop() {
  int randMov;
  randMov = random(0, 3);
  
  if(randMov == 0)
  {
    moveForward();
  }
  else if(randMov == 1)
  {
    moveBackward();
  }
  else if(randMov == 2)
  {
    moveLeft();
  } 
  else
  {
    moveRight();
  }
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
