#include <application.h>

String readString;

void setup(){
  Serial.begin(9600);
}

void loop(){
  //Waiting for user input on serial
  Serial.println("Type any character to start");
  while (Serial.available() <= 0) {
    delay(10);
  }

  //Get String from serial
  while (Serial.available()) {
  delay(3);  //delay to allow buffer to fill
  if (Serial.available() > 0) {
    char c = Serial.read();  //gets one byte from serial buffer
    readString += c; //makes the string readString
  }
}

size_t length = EEPROM.length();

Serial.println("length: " + String(length));
}
