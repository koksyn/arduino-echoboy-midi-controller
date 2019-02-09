#include "StateMachine.h"

//#include <SPI.h>

int sc_beat = 0;

StateMachine::StateMachine()
{
	this->down_at = 0;
	this->down = 0;
}

// Find the number of beats the button has been down for. Function can compute max. 8 sec down before rolling over.
byte StateMachine::downFor()
{
	byte time;
	if (this->down_at > sc_beat)
	{
		time = (sc_beat + 256) - this->down_at;
	}
	else
	{
		time = sc_beat - this->down_at;
	}
	return time;
}

bool StateMachine::isDown()
{
	return (bool)this->down;
}

void StateMachine::resetDown()
{
	this->down_at = sc_beat;
	this->down = 1;
}

void StateMachine::turnOn()
{
	if (!this->down)
	{
		this->down_at = sc_beat;
		this->down = 1;
	}
	return;
}

void StateMachine::turnOff()
{
	this->down = 0;
	return;
}