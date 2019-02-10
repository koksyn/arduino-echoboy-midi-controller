#ifndef Machine_h
#define Machine_h

//#include <ArduinoSTL.h>
#include "State.h"

class Machine {
	friend class State;

	private:
		State* currentState;
		void setState(State* state);
	public:
		StateMachine();
		void nextState();
		void executeCurrentState();

		virtual void setDefaultState();
};

#endif
