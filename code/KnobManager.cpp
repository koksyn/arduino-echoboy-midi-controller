#include "KnobManager.h"

uint8_t KnobManager::knobReadings[KNOBS][NUM_OF_READINGS];
int KnobManager::knobReadIndex[KNOBS];
uint8_t KnobManager::knobReadTotal[KNOBS];
uint8_t KnobManager::knobReadAverage[KNOBS];

void KnobManager::initialize()
{ 
    for(int knob = 0; knob < KNOBS; knob++) {
        if(knob==PIN_KNOB_INPUT) continue;
      
        // initialize index
        knobReadIndex[knob] = 0;

        // read Knob value
        uint8_t readedKnobValue = readKnob(knob);

        // initialize all the readings to the same 'ONCE' readed knob value
        // it's important, because we avoid sending MIDI change signal after Power Up
        for(int reading = 0; reading < NUM_OF_READINGS; reading++) {
            knobReadings[knob][reading] = readedKnobValue;
        }

        // calculate total and average (fixed, because of same knob value)
        knobReadTotal[knob] = readedKnobValue;
        knobReadAverage[knob] = readedKnobValue;
    }
}

void KnobManager::updateAllKnobs()
{
    if(readKnobAndSet(PIN_KNOB_ECHO_1_TIME)) {
        // send midi 1
        // lcd update 1

        // check that timing of Echo1 & Echo2 is in SYNC
        if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
            //lastKnobValue[PIN_KNOB_ECHO_2_TIME] = lastKnobValue[PIN_KNOB_ECHO_1_TIME];

            // send midi 2
            // lcd update 2
        }
    }
    if(readKnobAndSet(PIN_KNOB_ECHO_2_TIME)) {
        // send midi 2
        // lcd update 2

        // check that timing of Echo1 & Echo2 is in SYNC
        if(MachineFactory::get(MACHINE_SYNC_TIME)->equalsState(StateFactory::get(STATE_SYNC_TIME_ENABLED))) {
            //lastKnobValue[PIN_KNOB_ECHO_1_TIME] = lastKnobValue[PIN_KNOB_ECHO_2_TIME];

            // send midi 1
            // lcd update 1
        }
    }
    if(readKnobAndSet(PIN_KNOB_FEEDBACK)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_MIX)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_SATURATION)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_LOW_CUT)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_HIGH_CUT)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_OUTPUT)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_FEEL)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_GROOVE)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_RHYTM_REPEATS)) {
        // send midi
    }
    if(readKnobAndSet(PIN_KNOB_RHYTM_DECAY)) {
        // send midi
    }
}

int index = 0;
int average = 0;

// returns true if set was success
boolean KnobManager::readKnobAndSet(int knobPinNumber)
{
// trzeba spróbować to (o wiele lepsze rozwiązanie bez lagów)
    // https://github.com/dxinteractive/ResponsiveAnalogRead
    
    index = knobReadIndex[knobPinNumber];
    
    // subtract the last reading
    knobReadTotal[knobPinNumber] = knobReadTotal[knobPinNumber] - knobReadings[knobPinNumber][index];
    
    // read from the sensor
    knobReadings[knobPinNumber][index] = readKnob(knobPinNumber);
    
    // add the reading to the total:
    knobReadTotal[knobPinNumber] = knobReadTotal[knobPinNumber] + knobReadings[knobPinNumber][index];
    
    // advance to the next position in the array
    knobReadIndex[knobPinNumber]++;

    // reset to array start if exceeded number of readings
    if (knobReadIndex[knobPinNumber] >= NUM_OF_READINGS) {
        knobReadIndex[knobPinNumber] = 0;
    }

    average = knobReadTotal[knobPinNumber] / NUM_OF_READINGS;
 
    // this solution reduces electrical noise
    boolean allowedToSet = average != knobReadAverage[knobPinNumber];

    // delay in between reads for stability
    delay(1);

    if(allowedToSet) {
        knobReadAverage[knobPinNumber] = average;
        
        if(knobPinNumber == PIN_KNOB_ECHO_1_TIME)
        LcdManager::printTop(knobReadings[knobPinNumber][index]);
        
        if(knobPinNumber == PIN_KNOB_HIGH_CUT)
        LcdManager::printBottom(knobReadings[knobPinNumber][index]);
        
        return true;
    }
    return false;
}

uint8_t KnobManager::readKnob(uint8_t knobPinNumber)
{
    return PinFactory::get(knobPinNumber)->read();
    // map to midi values
    //return signal;//map(signal, 0, 255, 0, 127);
}
