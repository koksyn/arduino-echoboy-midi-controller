#include "MidiProxy.h"
#include "KnobManager.h"
#include "PinFactory.h"
#include "StateFactory.h"
#include "MachineFactory.h"
#include "InterruptionRouter.h"
#include "ButtonHandler.h"

#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>
//https://github.com/FortySevenEffects/arduino_midi_library/blob/master/src/MIDI.h

 // Created and binds the MIDI interface to the default hardware Serial port
 //
/*
 * Co brakuje:
 *
 * - jakie sygnały midi trzeba wyslac? i jaki typ?
 * - wyświetlanie czasów na ekranie i wciśniętych przycisków (stany) - czyli ekran musi być osobnym obiektem, aby tym sterował (blokował na sekundy)
 */

//
hd44780_I2Cexp lcd;
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

  InterruptionRouter::enableInterruptions();

  // initialize LCD with number of columns and rows:
  lcd.begin(20, 4);

  // Print a message to the LCD
  lcd.print("OK");
}

void loop() {
  // Send note 42 with velocity 127 on channel 1
  // MIDI.sendNoteOn(42, 127, 1);

  KnobManager::updateAllKnobs();
  ButtonHandler::handle(buttonPressed);

  // reset after handling
  if(buttonPressed > 0) {
    lcd.setCursor(0, 1);
    lcd.print(buttonPressed);
    
    buttonPressed = 0;
  }
}

// linux problems: sudo chmod a+rw /dev/ttyACM0
