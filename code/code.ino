#include "PinFactory.h"

Pin* pin;
Pin* pin2;
Pin* pin3;
//Pin* pin4;

void setup() {
  //start serial connection
  Serial.begin(9600);
  while (!Serial);

  pin = PinFactory::get("pin");
  pin2 = PinFactory::get("pin2");
  pin3 = PinFactory::get("pin3");
  //pin4 = PinFactory::get("pin4"); // led

  PinFactory::runIntegratedCircuits();
}

void loop() {
  Serial.println(pin2->read());
  Serial.println(pin3->read());

  //pin4->write(LOW);
  //delay(500);

  //pin4->write(HIGH);
  delay(500);
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
