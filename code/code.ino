#include "PinFactory.h"
#include "StateFactory.h"
#include "MachineFactory.h"
#include "InterruptionRouter.h"
#include "ButtonHandler.h"

 #include <MIDI.h>

#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

 // Created and binds the MIDI interface to the default hardware Serial port
 //MIDI_CREATE_DEFAULT_INSTANCE();

//
hd44780_I2Cexp lcd;
volatile uint8_t buttonPressed = 0;

void setup() {
  //Serial.begin(9600);
  //while (!Serial);

  //MIDI.begin(MIDI_CHANNEL_OMNI);  // Listen to all incoming messages

  PinFactory::initialize();
  PinFactory::runIntegratedCircuits();

  StateFactory::initialize();
  MachineFactory::initialize();

  InterruptionRouter::enableInterruptions();

  //Serial.println("Setup ready");

    //hd44780_I2Cexp *lcd = new hd44780_I2Cexp();
    // initialize LCD with number of columns and rows:
    lcd.begin(20, 4);

    // Print a message to the LCD
    lcd.print("OK");
}

void loop() {
  // Send note 42 with velocity 127 on channel 1
     //MIDI.sendNoteOn(42, 127, 1);

  //Serial.println("OK");

  // Arduino Analog + MCP3008 + Arduino Digital
  for(uint8_t i=0; i<=12; i++) {
      if(i==PIN_KNOB_INPUT) continue;

      //Serial.print(PinFactory::get(i)->read());
     // Serial.print(' ');
  }

  //Serial.println();
  delay(50);

  ButtonHandler::handle(buttonPressed);

  // reset after handling
  if(buttonPressed > 0) {
    lcd.setCursor(0, 1);
    lcd.print(buttonPressed);
    
    buttonPressed = 0;
  }
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
