#include "PinFactory.h"
#include "StateFactory.h"
#include "MachineFactory.h"
#include "InterruptionRouter.h"
#include "ButtonHandler.h"

 #include <MIDI.h>

 // Created and binds the MIDI interface to the default hardware Serial port
 //MIDI_CREATE_DEFAULT_INSTANCE();


volatile uint8_t buttonPressed = 0;

void setup() {
  Serial.begin(9600);
  while (!Serial);

  //MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages

  PinFactory::initialize();
  PinFactory::runIntegratedCircuits();

  StateFactory::initialize();
  MachineFactory::initialize();

  InterruptionRouter::enableInterruptions();

  Serial.println("Setup ready");
}

void loop() {
  // Send note 42 with velocity 127 on channel 1
     //MIDI.sendNoteOn(42, 127, 1);

  //Serial.println("OK");

  //delay(50);

  ButtonHandler::handle(buttonPressed);

  // reset after handling
  if(buttonPressed > 0) {
    //Serial.println(buttonPressed);
    
    buttonPressed = 0;
  }
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
