#include "application.h"

uint16_t fromEEPROMString;

void setup() {
  Serial.begin(9600);

  //Clearing the EEPROM
  EEPROM.clear(); Serial.println("EEPROM Cleared!");

  //Waiting for user input on serial
  Serial.println("Type any character to start");
  while (Serial.available() <= 0) {
    delay(1000);
  }

  //Get lenght of EEPROM and print it.
  size_t length = EEPROM.length();
  Serial.println("length: " + String(length));

  for(int i = 0; i < EEPROM.length()-2; i++){
    //Getting the value from addresses
    EEPROM.get(i, fromEEPROMString);

    Serial.println("Address: " + String(i) + " : //" + String(fromEEPROMString,(unsigned int)16) + "//");
    delay(1);
  }
}

void loop() {

}
