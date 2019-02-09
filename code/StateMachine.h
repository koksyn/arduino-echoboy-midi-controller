#ifndef StateMachine_h
#define StateMachine_h

#include <Arduino.h>

class StateMachine {
private:
	byte down_at;
	byte down;

public:
	StateMachine();
	void addState(Pin pin,)

	byte downFor();
	void resetDown();
	bool isDown();
	void turnOn();
	void turnOff();
};

#endif