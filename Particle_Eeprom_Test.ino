#include "application.h"

String fromSerialString;
uint16_t fromEEPROMString;
long EEPROMAddress;

void setup() {
  Serial.begin(9600);

  //Waiting for user input on serial
  Serial.println("Type any character to start");
  while (Serial.available() <= 0) {
    delay(1000);
  }

  //Get lenght of EEPROM and print it.
  size_t length = EEPROM.length();
  Serial.println("length: " + String(length));
}

void loop() {

}
