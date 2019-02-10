#ifndef INTERRUPTION_ROUTER_H
#define INTERRUPTION_ROUTER_H

// DIP MIDI
extern volatile bool dipMidi1ButtonPressed = false;
extern volatile bool dipMidi2ButtonPressed = false;
extern volatile bool dipMidi3ButtonPressed = false;
extern volatile bool dipMidi4ButtonPressed = false;

// STYLE
extern volatile bool tapeStyleButtonPressed = false;
extern volatile bool echoStyleButtonPressed = false;
extern volatile bool bbdStyleButtonPressed = false;
extern volatile bool biasStyleButtonPressed = false;
extern volatile bool chorusStyleButtonPressed = false;
extern volatile bool atmoStyleButtonPressed = false;

// MASTER
extern volatile bool midiAllButtonPressed = false;
extern volatile bool bypassButtonPressed = false;

// MODE
extern volatile bool modeButtonPressed = false;

// ECHO1 & ECHO2
extern volatile bool echo1ButtonPressed = false;
extern volatile bool echo2ButtonPressed = false;

// LCD
extern volatile bool syncTimeButtonPressed = false;
extern volatile bool primeNumbersButtonPressed = false;

class InterruptionRouter {
public:
    static void enableInterruptions();
};

#endif
