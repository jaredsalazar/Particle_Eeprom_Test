#include "application.h"

void setup() {
  Serial.begin(9600);

  //Waiting for user input on serial
  Serial.println("Type any character to start");
  while (Serial.available() <= 0) {
    delay(1000);
  }

  // Read a value (2 bytes in this case) from EEPROM addres
  int addr = 10;
  uint16_t value;
  EEPROM.get(addr, value);
  if(value == 0xFFFF) {
    // EEPROM was empty -> initialize value
    value = 25;
  }

  // Read an object from the EEPROM addres
  addr = 20;
  struct MyObject {
    uint8_t version;
    float field1;
    uint16_t field2;
    char name[10];
  };
  MyObject myObj;
  EEPROM.get(addr, myObj);
  if(myObj.version != 0) {
    // EEPROM was empty -> initialize myObj
    MyObject defaultObj = { 0, 12.34f, 25, "Test!!" };
    myObj = defaultObj;
  }

  Serial.println("value: " + String(value));
  Serial.println("version: " + String(myObj.version) + " field1: " + String(myObj.field1) + " field2: " + String(myObj.field2) + " name: " + String(myObj.name));
}

void loop() {

}
