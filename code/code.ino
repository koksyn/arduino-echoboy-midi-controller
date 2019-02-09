#include "ArduinoDigitalPin.h"
#include "ArduinoAnalogPin.h"

Pin* pin;
Pin* pin2;

void setup() {
  //start serial connection
  Serial.begin(9600);

  pin = (Pin*) new ArduinoDigitalPin(5, OUTPUT);
  pin2 = (Pin*) new ArduinoAnalogPin(A5, INPUT_PULLUP);
}

void loop() {
  
  Serial.println(pin2->read());

  pin->write(LOW);
  delay(2000);

  pin->write(HIGH);
  delay(2000);
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
