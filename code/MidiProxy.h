#ifndef MIDI_PROXY_H
#define MIDI_PROXY_H

#include <MIDI.h>


#define MIDI_DEFAULT_CHANNEL 10
#define MIDI_MAX_VALUE 127

#define CC_ECHO_1_TIME 22
#define CC_MODE 23

#define NOTE_C2 36

class MidiProxy {
private:
    static uint8_t channel;
public:
    static void initialize();
    static void setChannel(uint8_t newChannel);
    static void sendNote(int noteNumber);
    static void sendCC(int controlNumber, int controlValue);
    static void sendStepByCC(int controlNumber, int step, int totalSteps);
};

#endif
