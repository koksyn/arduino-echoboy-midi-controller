#include "pin/ArduinoDigitalPin.h"

ArduinoDigitalPin pin;

void setup() {
  //start serial connection
  Serial.begin(9600);

  pin = new ArduinoDigitalPin(3, OUTPUT);

  pin.write(HIGH);
}

void loop() {
  
  Serial.println("OK");

  delay(2000);
}
