#include "MidiProxy.h"
#include "PinFactory.h"
#include "StateFactory.h"
#include "MachineFactory.h"
#include "InterruptionRouter.h"
#include "ButtonHandler.h"

#include <Wire.h>
#include <hd44780.h>
#include <hd44780ioClass/hd44780_I2Cexp.h>

 // Created and binds the MIDI interface to the default hardware Serial port
 //
/*
 * Co brakuje:
 *
 * - jakie sygnały midi trzeba wyslac? i jaki typ?
 * - odczyt potencjometrów aby wysyłać sygnały midi
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

  InterruptionRouter::enableInterruptions();

  // initialize LCD with number of columns and rows:
  lcd.begin(20, 4);

  // Print a message to the LCD
  lcd.print("OK");
}

void loop() {
  // Send note 42 with velocity 127 on channel 1
     //MIDI.sendNoteOn(42, 127, 1);

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
