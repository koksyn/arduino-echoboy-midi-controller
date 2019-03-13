#include "MidiProxy.h"
#include "KnobManager.h"
#include "PinFactory.h"
#include "StateFactory.h"
#include "MachineFactory.h"
#include "InterruptionRouter.h"
#include "ButtonHandler.h"
#include "LcdManager.h"

volatile uint8_t buttonPressed = 0;

void setup() {
  MidiProxy::initialize();

  PinFactory::initialize();
  PinFactory::runIntegratedCircuits();

  StateFactory::initialize();
  MachineFactory::initialize();
  
  KnobManager::initialize();
  
  InterruptionRouter::enableInterruptions();

  LcdManager::initialize();
  LcdManager::printFirstRow();
  LcdManager::printSecondRow();

   KnobManager::updateAllKnobs();
}

void loop() {
 

  ButtonHandler::handle(buttonPressed);

  // reset after handling
  if(buttonPressed > 0) {
    buttonPressed = 0;
  }
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
