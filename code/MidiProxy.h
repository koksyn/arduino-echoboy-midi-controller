#ifndef MIDI_PROXY_H
#define MIDI_PROXY_H

#include <MIDI.h>
#include "PinFactory.h"

#define SERIAL_MIDI_BIT_RATE 9600
#define MIDI_DEFAULT_CHANNEL 10
#define MIDI_MAX_VALUE 127

// knobs
#define CC_ECHO_1_TIME 22
#define CC_ECHO_2_TIME 23
#define CC_FEEDBACK 24
#define CC_MIX 25
#define CC_SATURATION 26
#define CC_LOW_CUT 27
#define CC_HIGH_CUT 28
#define CC_INPUT 29
#define CC_OUTPUT 30
#define CC_FEEL 31
#define CC_GROOVE 32
#define CC_RHYTM_REPEATS 33
#define CC_RHYTM_DECAY 34

// steps / modes / styles
#define CC_MODE 35
#define CC_ECHO_1_DIVISION 36
#define CC_ECHO_2_DIVISION 37
#define CC_STYLE 38

// Notes (for buttons) on/off
#define CC_BYPASS 39
#define CC_PRIME_NUMBERS 40

class MidiProxy {
private:
    static uint8_t channel;
    static boolean channelBtnLastValue[4];
    static uint8_t boolArrayToByte(bool* boolArray);
public:
    static void initialize();
    static void setChannel(uint8_t newChannel);
    static void sendNote(uint8_t noteNumber);
    static void sendCC(uint8_t controlNumber, uint8_t controlValue);
    static void sendStepByCC(uint8_t controlNumber, uint8_t step, uint8_t totalSteps);
    static void listenForMidiChannelChanges();
};

#endif
