#ifndef Machine_h
#define Machine_h

//#include <ArduinoSTL.h>

class State;
#include "State.h"

class Machine {
	friend class State;

	private:
		State* currentState;
	protected:
		void setState(State* state);
	public:
		Machine();
		void nextState();
		void executeCurrentState();

		virtual void setDefaultState();
};

#endif
