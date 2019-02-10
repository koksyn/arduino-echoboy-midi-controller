#ifndef Machine_h
#define Machine_h

#include "State.h"

class Machine {
	friend class State;

	private:
		State* currentState;
	protected:
		void setState(State* state);
	public:
		void nextState();
		void executeCurrentState();

		virtual void setDefaultState();
};

#endif
