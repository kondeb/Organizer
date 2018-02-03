#pragma once
#include "Event.h"
class LongTermEvent : public Event {
	
	int LastingTime;

public:
	LongTermEvent() {};

	LongTermEvent(int startingtime, int endingtime, std::string description, Person man, int lastingtime):Event(startingtime, endingtime, description,  man)
	{
		this->LastingTime = lastingtime;
	}

	~LongTermEvent() {};
};