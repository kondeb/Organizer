#pragma once
#include "Event.h"

class PeriodicEvent : public Event {
	
	int Period;
	int PeriodLasting;

public:
	PeriodicEvent(int startingtime, int endingtime, std::string description, Person man, int period, int periodlasting):Event(startingtime,  endingtime,  description,  man)
	{
		this->Period = period;
		this->PeriodLasting = periodlasting;
	}
	PeriodicEvent() {};

	~PeriodicEvent() {};
};