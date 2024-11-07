#include <IRremote.h>

int receiverPin = 12;
unsigned long lastReceivedTime = 0;

#define PIN1 10
#define PIN2 11
#define PIN3 6
#define PIN4 7

void setup() {
  pinMode(PIN1, OUTPUT);
  pinMode(PIN2, OUTPUT);
  pinMode(PIN3, OUTPUT);
  pinMode(PIN4, OUTPUT);
  
  Serial.begin(9600);         // Begin Serial for debugging
  IrReceiver.begin(receiverPin, ENABLE_LED_FEEDBACK);  // Start the IR receiver with feedback LED
}

void loop() 
{
  if (IrReceiver.decode()) 
  {
    unsigned long irValue = IrReceiver.decodedIRData.decodedRawData; // Get received value
    Serial.println(irValue, HEX); // Print received value for debugging
    translateIR(irValue);  // Pass the received value to translate function
    lastReceivedTime = millis();
    IrReceiver.resume();   // Prepare for the next value
  }

    if (millis() - lastReceivedTime > 200) {
    stopCar();  // Stop the car if the button is no longer being held
  }
}

void translateIR(unsigned long value)
{
  switch (value)
  {
    case 0xB946FF00: moveForward(); break; // vol+
    case 0xBC43FF00: moveRight(); break;   // ffw
    case 0xEA15FF00: moveBackward(); break; // vol-
    case 0xBB44FF00: moveLeft(); break;    // bt
  }
}

void moveForward()
{
  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, HIGH);
  digitalWrite(PIN4, LOW);
}

void moveBackward()
{
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN2, HIGH);
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, HIGH);
}

void moveLeft()
{
  digitalWrite(PIN1, HIGH);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, HIGH);
}

void moveRight()
{
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN2, HIGH);
  digitalWrite(PIN3, HIGH);
  digitalWrite(PIN4, LOW);
}

void stopCar()
{
  digitalWrite(PIN1, LOW);
  digitalWrite(PIN2, LOW);
  digitalWrite(PIN3, LOW);
  digitalWrite(PIN4, LOW);
}
