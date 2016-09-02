#include "application.h"

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

  // Write an object to the EEPROM address
  int addr = 20;
  struct MyObject {
    uint8_t version;
    float field1;
    uint16_t field2;
    String name;
  };
  MyObject myObj = { 0, 12.34f, 25, "Test!" };
  EEPROM.put(addr, myObj);
}

void loop() {

}
