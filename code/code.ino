#include "PinFactory.h"
#include "StateFactory.h"
#include "MachineFactory.h"
#include "InterruptionRouter.h"

// DIP MIDI
#include "DipMidi1ButtonHandler.h"
volatile bool dipMidi1ButtonPressed = false;
#include "DipMidi2ButtonHandler.h"
volatile bool dipMidi2ButtonPressed = false;
#include "DipMidi3ButtonHandler.h"
volatile bool dipMidi3ButtonPressed = false;
#include "DipMidi4ButtonHandler.h"
volatile bool dipMidi4ButtonPressed = false;

// STYLE
#include "TapeStyleButtonHandler.h"
volatile bool tapeStyleButtonPressed = false;
#include "EchoStyleButtonHandler.h"
volatile bool echoStyleButtonPressed = false;
#include "BbdStyleButtonHandler.h"
volatile bool bbdStyleButtonPressed = false;
#include "BiasStyleButtonHandler.h"
volatile bool biasStyleButtonPressed = false;
#include "ChorusStyleButtonHandler.h"
volatile bool chorusStyleButtonPressed = false;
#include "AtmoStyleButtonHandler.h"
volatile bool atmoStyleButtonPressed = false;

// MASTER
#include "MidiAllButtonHandler.h"
volatile bool midiAllButtonPressed = false;
#include "BypassButtonHandler.h"
volatile bool bypassButtonPressed = false;

// MODE
#include "ModeButtonHandler.h"
volatile bool modeButtonPressed = false;

// ECHO1 & ECHO2
#include "Echo1ButtonHandler.h"
volatile bool echo1ButtonPressed = false;
#include "Echo2ButtonHandler.h"
volatile bool echo2ButtonPressed = false;

// LCD
#include "SyncTimeButtonHandler.h"
volatile bool syncTimeButtonPressed = false;
#include "PrimeNumbersButtonHandler.h"
volatile bool primeNumbersButtonPressed = false;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  PinFactory::initialize();
  StateFactory::initialize();
  MachineFactory::initialize();

  PinFactory::runIntegratedCircuits();
  InterruptionRouter::enableInterruptions();
}

void loop() {
  Serial.println("Loop works");

  delay(50);

  // DIP MIDI
  if(dipMidi1ButtonPressed) { DipMidi1ButtonHandler::handle(); dipMidi1ButtonPressed = false; }
  if(dipMidi2ButtonPressed) { DipMidi2ButtonHandler::handle(); dipMidi2ButtonPressed = false; }
  if(dipMidi3ButtonPressed) { DipMidi3ButtonHandler::handle(); dipMidi3ButtonPressed = false; }
  if(dipMidi4ButtonPressed) { DipMidi4ButtonHandler::handle(); dipMidi4ButtonPressed = false; }

  // STYLE
  if(tapeStyleButtonPressed) { TapeStyleButtonHandler::handle(); tapeStyleButtonPressed = false; }
  if(echoStyleButtonPressed) { EchoStyleButtonHandler::handle(); echoStyleButtonPressed = false; }
  if(bbdStyleButtonPressed) { BbdStyleButtonHandler::handle(); bbdStyleButtonPressed = false; }
  if(biasStyleButtonPressed) { BiasStyleButtonHandler::handle(); biasStyleButtonPressed = false; }
  if(chorusStyleButtonPressed) { ChorusStyleButtonHandler::handle(); chorusStyleButtonPressed = false; }
  if(atmoStyleButtonPressed) { AtmoStyleButtonHandler::handle(); atmoStyleButtonPressed = false; }

  // MASTER
  if(midiAllButtonPressed) { MidiAllButtonHandler::handle(); midiAllButtonPressed = false; }
  if(bypassButtonPressed) { BypassButtonHandler::handle(); bypassButtonPressed = false; }

  // MODE
  if(modeButtonPressed) { ModeButtonHandler::handle(); modeButtonPressed = false; }

  // ECHO1 & ECHO2
  if(echo1ButtonPressed) { Echo1ButtonHandler::handle(); echo1ButtonPressed = false; }
  if(echo2ButtonPressed) { Echo2ButtonHandler::handle(); echo2ButtonPressed = false; }

  // LCD
  if(syncTimeButtonPressed) { SyncTimeButtonHandler::handle(); syncTimeButtonPressed = false; }
  if(primeNumbersButtonPressed) { PrimeNumbersButtonHandler::handle(); primeNumbersButtonPressed = false; }
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
