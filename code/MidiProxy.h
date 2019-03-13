#ifndef MIDI_PROXY_H
#define MIDI_PROXY_H

#include <MIDI.h>

#define MIDI_DEFAULT_CHANNEL 10

class MidiProxy {
private:
    static uint8_t channel;
public:
    static void initialize();
    static void setChannel(uint8_t channel);
    // not implemented static void send();
};

#endif
