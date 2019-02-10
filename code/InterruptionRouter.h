#ifndef INTERRUPTION_ROUTER_H
#define INTERRUPTION_ROUTER_H

// DIP MIDI
extern volatile bool dipMidi1ButtonPressed;
extern volatile bool dipMidi2ButtonPressed;
extern volatile bool dipMidi3ButtonPressed;
extern volatile bool dipMidi4ButtonPressed;

// STYLE
extern volatile bool tapeStyleButtonPressed;
extern volatile bool echoStyleButtonPressed;
extern volatile bool bbdStyleButtonPressed;
extern volatile bool biasStyleButtonPressed;
extern volatile bool chorusStyleButtonPressed;
extern volatile bool atmoStyleButtonPressed;

// MASTER
extern volatile bool midiAllButtonPressed;
extern volatile bool bypassButtonPressed;

// MODE
extern volatile bool modeButtonPressed;

// ECHO1 & ECHO2
extern volatile bool echo1ButtonPressed;
extern volatile bool echo2ButtonPressed;

// LCD
extern volatile bool syncTimeButtonPressed;
extern volatile bool primeNumbersButtonPressed;

class InterruptionRouter {
public:
    static void enableInterruptions();
};

#endif
