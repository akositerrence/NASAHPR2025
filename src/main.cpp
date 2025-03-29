#include <Arduino.h>
#include <SPI.h>

const int PrimaryIMUSlaveSelectPin = 12;


void setup() {

  Serial.begin(115200);
  Serial.println("flag 1");
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(PrimaryIMUSlaveSelectPin, OUTPUT);
  digitalWrite(PrimaryIMUSlaveSelectPin, HIGH);
  SPI.begin();

}


void loop() {

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);

  digitalWrite(PrimaryIMUSlaveSelectPin, LOW);
  byte response = SPI.transfer(0xFF);
  digitalWrite(PrimaryIMUSlaveSelectPin, HIGH);

  Serial.print(response);

  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);

}