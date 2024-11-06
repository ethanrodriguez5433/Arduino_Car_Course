//**********************************************************/
// Edit Code Below
//Write the numbers on the arduino Associated with the 
//four pins for the motors next to each define statement
//
//Ex: #define PIN1 13
//**********************************************************/

#define PIN1 10
#define PIN2 11
#define PIN3 6
#define PIN4 7
/**********************************************************/
//
/**********************************************************/


void setup() {
  pinMode(PIN1, OUTPUT);  //PIN 1 FOR MOTOR 1
  pinMode(PIN2, OUTPUT);  //PIN 2 FOR MOTOR 1
  pinMode(PIN3, OUTPUT);  //PIN 3 FOR MOTOR 2
  pinMode(PIN4, OUTPUT);  //PIN 4 FOR MOTOR 2
}

void loop() 
{
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
  else if(randMov == 3)
  {
    moveRight();
  }
}


//***************************************/
//Edit Code below
//Change the assignment of the pins below (HIGH/LOW)
//so that both motors move in the proper direction
//
//Use moveForward() as an example
//**************************************/


void moveForward()
{
  //set pins 1 & 4 to low and 2 & 3 to high
  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, HIGH);
  digitalWrite(PIN4, LOW);
  delay(1000);
}

void moveBackward()
{
  //set pins 2 & 3 to low and 1 & 4 to high
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN2, HIGH);
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, HIGH);
  delay(1000);
}

void moveLeft()
{
  //set pins 1 & 3 to high and 2 & 4 to low 
  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, HIGH);
  delay(300);
}

void moveRight()
{
  //set pins 2 & 4 to high and 1 & 3 to low
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN2, HIGH);
  digitalWrite(PIN3, HIGH);
  digitalWrite(PIN4, LOW);
  delay(300);
}


//**********************************************
//For more practice, change the value in delay()
//This will affect how long each motion is performed
//ex: delay(600)
//
//Try changing the delay so that in one turn
//the car rotates 90 degrees
//Hint: You may need to utilize stopCar()
//Hint: delay() takes a number of miliseconds (600 = 600 miliseconds)
//***********************************************

void stopCar()
{
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, LOW);
  delay(1000);
}