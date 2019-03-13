#include "MidiProxy.h"
#include "KnobManager.h"
#include "PinFactory.h"
#include "StateFactory.h"
#include "MachineFactory.h"
#include "InterruptionRouter.h"
#include "ButtonHandler.h"
#include "LcdManager.h"

//hd44780_I2Cexp lcd;
volatile uint8_t buttonPressed = 0;

void setup() {
  //Serial.begin(9600);
  //while (!Serial);

  MidiProxy::initialize();

  PinFactory::initialize();
  PinFactory::runIntegratedCircuits();

  StateFactory::initialize();
  MachineFactory::initialize();

  KnobManager::initialize();
  LcdManager::initialize();

  InterruptionRouter::enableInterruptions();
}

void loop() {
  KnobManager::updateAllKnobs();

  ButtonHandler::handle(buttonPressed);

  // reset after handling
  if(buttonPressed > 0) {
    buttonPressed = 0;
  }
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
