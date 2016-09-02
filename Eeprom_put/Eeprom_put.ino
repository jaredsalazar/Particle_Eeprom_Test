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
  struct MyObject {
      bool stat;
      bool bat;
      char msg[20];
    };

  addr = 20;
  MyObject myObj1 = { 0,0,"AAAAA11111222223333" };
  EEPROM.put(addr, myObj1);
  Serial.println("Success. Size: " + String(sizeof(myObj1)));

  addr = 40;
  MyObject myObj2 = { 1,1,"AAAAA77777888889999" };
  EEPROM.put(addr, myObj2);
  Serial.println("Success. Size: " + String(sizeof(myObj2)));

}

void loop() {

}
