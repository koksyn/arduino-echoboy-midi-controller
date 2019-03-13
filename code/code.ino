#include "MidiProxy.h"
#include "KnobManager.h"
#include "PinFactory.h"
#include "StateFactory.h"
#include "MachineFactory.h"
#include "InterruptionRouter.h"
#include "ButtonHandler.h"
#include "LcdManager.h"

hd44780_I2Cexp lcd(0x27);

volatile uint8_t buttonPressed = 0;

void setup() {
  //MidiProxy::initialize();

  PinFactory::initialize();
  PinFactory::runIntegratedCircuits();

  StateFactory::initialize();
  MachineFactory::initialize();
  
  //KnobManager::initialize();
  
  //InterruptionRouter::enableInterruptions();

  //LcdManager::initialize(&lcd);
  //LcdManager::printFirstRow();
  //LcdManager::printSecondRow();
}

void loop() {
  //KnobManager::updateAllKnobs();

  //ButtonHandler::handle(buttonPressed);

  // reset after handling
  if(buttonPressed > 0) {
    buttonPressed = 0;
  }
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
