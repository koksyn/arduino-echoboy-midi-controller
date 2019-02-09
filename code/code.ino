#include "ArduinoDigitalPin.h"

ArduinoDigitalPin* pin;

void setup() {
  //start serial connection
  Serial.begin(9600);

  pin = new ArduinoDigitalPin(5, OUTPUT);

  pin->write(HIGH);
}

void loop() {
  
  Serial.println("OK");

  pin->write(LOW);
  delay(2000);

  pin->write(HIGH);
  delay(2000);
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
