#include "MidiProxy.h"

uint8_t MidiProxy::channel;

// https://github.com/FortySevenEffects/arduino_midi_library/blob/master/src/MIDI.h

// Created and binds the MIDI interface to the Hairless MIDI Serial Bus
struct HairlessMidiSettings : public midi::DefaultSettings
{
    static const bool UseRunningStatus = false; // it's very important to have this 'extra' status disabled
    static const long BaudRate = SERIAL_MIDI_BIT_RATE;
};
MIDI_CREATE_CUSTOM_INSTANCE(HardwareSerial, Serial, MIDI, HairlessMidiSettings);

void MidiProxy::initialize()
{
    // Default channel
    channel = MIDI_DEFAULT_CHANNEL;

    // Listen to all incoming messages
    MIDI.begin(MIDI_CHANNEL_OMNI);
}

void MidiProxy::setChannel(uint8_t newChannel)
{
    channel = newChannel;
}

void MidiProxy::sendNote(int noteNumber)
{
    MIDI.sendNoteOn(noteNumber, 127, channel);
    delay(5);
    MIDI.sendNoteOff(noteNumber, 0, channel);
}

void MidiProxy::sendCC(int controlNumber, int controlValue)
{
    MIDI.sendControlChange(controlNumber, controlValue, channel);
}

void MidiProxy::sendStepByCC(int controlNumber, int step, int totalSteps)
{
    int interval = MIDI_MAX_VALUE / totalSteps;
    int pivot = (interval/2);
    int controlValueForStep = ((step - 1) * interval) + pivot;

    sendCC(controlNumber, controlValueForStep);
}
