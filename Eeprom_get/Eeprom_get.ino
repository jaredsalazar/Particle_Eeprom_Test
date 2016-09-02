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
  struct MyObject {
    bool stat;
    bool bat;
    char msg[20];
  };
  MyObject myObj1;
  addr = 20;
  EEPROM.get(addr, myObj1);
  Serial.println("value: " + String(value));
  Serial.println("stat: "+ String(myObj1.stat) + " name: " + String(myObj1.msg));

  MyObject myObj2;
  addr = 40;
  EEPROM.get(addr, myObj2);
  Serial.println("value: " + String(value));
  Serial.println("stat: "+ String(myObj2.stat) + " name: " + String(myObj2.msg));
}

void loop() {

}
