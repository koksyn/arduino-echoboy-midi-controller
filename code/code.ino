#include "ArduinoDigitalPin.h"
#include "ArduinoAnalogPin.h"
#include "Mcp3008Pin.h"

Pin* pin;
Pin* pin2;
Pin* pin3;

void setup() {
  //start serial connection
  Serial.begin(9600);
  while (!Serial);

  pin = (Pin*) new ArduinoDigitalPin(5, OUTPUT);
  pin2 = (Pin*) new ArduinoAnalogPin(A5, INPUT);
  pin3 = (Pin*) new Mcp3008Pin(1, INPUT);
}

void loop() {
  
  Serial.println(pin2->read());
  Serial.println(pin3->read());

  pin->write(LOW);
  delay(2000);

  pin->write(HIGH);
  delay(2000);
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
