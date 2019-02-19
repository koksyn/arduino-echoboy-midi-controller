#ifndef Machine_h
#define Machine_h

#include "State.h"

class Machine {
	friend class State;

	private:
		State* currentState;
		State* initialState;
	public:
		Machine(State* initialState);
		void nextState();
		void applyInitialState();
		void executeCurrentState();
		void setState(State* state);
		bool equalsState(State* state);
};

#endif
