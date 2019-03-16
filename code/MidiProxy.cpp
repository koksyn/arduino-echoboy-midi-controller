#include "MidiProxy.h"

uint8_t MidiProxy::channel;

// https://github.com/FortySevenEffects/arduino_midi_library/blob/master/src/MIDI.h
// Send note 42 with velocity 127 on channel 1
// MIDI.sendNoteOn(42, 127, 1);

// Created and binds the MIDI interface to the default hardware Serial port
MIDI_CREATE_DEFAULT_INSTANCE();

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
