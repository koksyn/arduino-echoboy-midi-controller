#include "ArduinoDigitalPin.h"

ArduinoDigitalPin* pin;

void setup() {
  //start serial connection
  Serial.begin(9600);

  pinMode(3, OUTPUT);
  pin = new ArduinoDigitalPin(3, OUTPUT);

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
