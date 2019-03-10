#include "PinFactory.h"
#include "StateFactory.h"
#include "MachineFactory.h"
#include "InterruptionRouter.h"
#include "ButtonHandler.h"

volatile uint8_t buttonPressed = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  PinFactory::initialize();
  PinFactory::runIntegratedCircuits();

  //StateFactory::initialize();
  //MachineFactory::initialize();

  InterruptionRouter::enableInterruptions();

  Serial.println("Setup ready");
}

void loop() {
  //Serial.println("OK");

  //delay(50);

  //ButtonHandler::handle(buttonPressed);

  // reset after handling
  if(buttonPressed > 0) {
    Serial.println(buttonPressed);
    
    buttonPressed = 0;
  }
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
