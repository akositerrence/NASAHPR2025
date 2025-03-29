#include <Arduino.h>
#include <SPI.h>

const int PrimaryIMUSlaveSelectPin = 10;

void setup() {

  Serial.begin(9600);
  while (!Serial) { ; } 

  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PrimaryIMUSlaveSelectPin, OUTPUT);
  digitalWrite(PrimaryIMUSlaveSelectPin, HIGH);

  SPI.begin();

}

void loop() {

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  Serial.println("Output Flag");

  digitalWrite(PrimaryIMUSlaveSelectPin, LOW);
  byte received = SPI.transfer(0xFF);
  digitalWrite(PrimaryIMUSlaveSelectPin, HIGH);

  Serial.println(received);

  digitalWrite(LED_BUILTIN, LOW);
  delay(500);

}