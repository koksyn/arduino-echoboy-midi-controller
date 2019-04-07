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
  Serial.begin(SERIAL_MIDI_BIT_RATE);

  PinFactory::initialize();
  PinFactory::runIntegratedCircuits();

  MidiProxy::initialize();

  StateFactory::initialize();
  MachineFactory::initialize();
  
  KnobManager::initialize();
  
  InterruptionRouter::enableInterruptions();

  LcdManager::initialize();
}

void loop() {
  MidiProxy::listenForMidiChannelChanges();

  KnobManager::updateAllKnobs();
  ButtonHandler::handle(buttonPressed);
  
  // reset after handling
  if(buttonPressed > 0) {
    // LcdManager::printTop(buttonPressed); // for debugging only
    buttonPressed = 0;
  }
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
