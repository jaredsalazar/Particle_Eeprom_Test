#include "application.h"

void setup() {
  Serial.begin(9600);

  //Waiting for user input on serial
  Serial.println("Type any character to start");
  while (Serial.available() <= 0) {
    delay(1000);
  }
  // Write a value (2 bytes in this case) to the EEPROM address
  int addr = 10;
  uint16_t value = 12345;
  EEPROM.put(addr, value);

  // Write an object to the EEPROM address
  addr = 20;
  struct MyObject {
    uint8_t version;
    float field1;
    uint16_t field2;
    char name[10];
  };
  MyObject myObj = { 0, 12.34f, 25, "Test!" };
  EEPROM.put(addr, myObj);
}

void loop() {

}
