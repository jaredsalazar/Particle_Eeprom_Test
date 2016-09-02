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

  for(int i = 0; i < EEPROM.length()-2; i++){
    //Getting the value from addresses
    EEPROM.get(i, fromEEPROMString);
    if (fromEEPROMString == 0xFFFF) {
      // EEPROM was empty -> initialize value
      fromEEPROMString = 0xFFFF;
    }

    Serial.println("Address: " + String(i) + " : //" + String(fromEEPROMString) + "//");
    delay(1);
  }
}

void loop() {

}
