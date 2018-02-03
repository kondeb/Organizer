#pragma once
#include "Day.h"
#include "Dimensions.h"
#include <SFML/Graphics.hpp>

class Week {

	std::vector<Day*> Days;

	int FirstDayOfMonth;

public:

	Week(std::vector<Day*> mDays, int mFirstDayOfMonth) {

		Days = mDays;
		FirstDayOfMonth = mFirstDayOfMonth;
	}



};