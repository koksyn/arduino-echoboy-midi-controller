#include "ArduinoDigitalPin.h"
#include "ArduinoAnalogPin.h"
#include "Mcp3008Pin.h"

#include "PinFactory.h"

Pin* pin;
Pin* pin2;
Pin* pin3;

void setup() {
  //start serial connection
  Serial.begin(9600);
  while (!Serial);

  pin = PinFactory::get("pin");
  pin2 = PinFactory::get("pin2");
  pin3 = PinFactory::get("pin3");
}

void loop() {
  
  Serial.println(pin2->read());
  Serial.println(pin3->read());

  pin->write(LOW);
  delay(500);

  pin->write(HIGH);
  delay(500);
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
