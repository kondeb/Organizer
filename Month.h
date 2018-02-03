#pragma once
#include "Day.h"
#include <string.h>

extern sf::RenderWindow window;

class Month
{
	const std::string Name;
	const int NumberOfDaysInMonth;
	const int Number;
	const int FirstDayOfMonth;

	int Week = -1;	//	Only to display week

	int NumberOfDays(int monthNumber, int year)
	{
		// January
		if (monthNumber == 0)
			return (31);

		// February
		if (monthNumber == 1)
		{
			// If the year is leap then February has
			// 29 days
			if (year % 400 == 0 ||
				(year % 4 == 0 && year % 100 != 0))
				return (29);
			else
				return (28);
		}

		// March
		if (monthNumber == 2)
			return (31);

		// April
		if (monthNumber == 3)
			return (30);

		// May
		if (monthNumber == 4)
			return (31);

		// June
		if (monthNumber == 5)
			return (30);

		// July
		if (monthNumber == 6)
			return (31);

		// August
		if (monthNumber == 7)
			return (31);

		// September
		if (monthNumber == 8)
			return (30);

		// October
		if (monthNumber == 9)
			return (31);

		// November
		if (monthNumber == 10)
			return (30);

		// December
		if (monthNumber == 11)
			return (31);
	}

	int DayNumber(int day, int month, int year)
	{

		static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
			4, 6, 2, 4 };
		year -= month < 3;
		return (year + year / 4 - year / 100 +
			year / 400 + t[month - 1] + day) % 7;
	}

	void displayWeek() {


		sf::Text Text;

		Text.setFont(dim::font);
		Text.setFillColor(sf::Color::White);
		Text.setCharacterSize(dim::TextSize_Month);


		for (int i = 0; i < 7; i++) {

			Text.setPosition(dim::DayNamesOffset + sf::Vector2f(i*dim::OffestBetweenItems_Month.x, 0));
			Text.setString(dim::DayNames.at(i));

			window.draw(Text);
		}


		int CountNumberOfDays = Week == 0 ? 1 : (Week - 1) * 7 + (8 - FirstDayOfMonth);

		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfItem_Week);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineThickness(dim::OutlineThickness_Week);

		for (int X = 0; (X < 7 && CountNumberOfDays <= NumberOfDaysInMonth); X++) {

			Item.setSize(dim::SizeOfItem_Week);

			if ((X >= FirstDayOfMonth && Week == 0) || Week > 0) {


				if (Days.at(CountNumberOfDays - 1)->HaveAnyEvent()) {

					std::vector<Event*> EventList = Days.at(CountNumberOfDays - 1)->returnEventList();

					if (!EventList.empty()) {

						sf::RectangleShape ItemE;
						sf::Text TextE, TextEE;

						TextE.setFont(dim::font);
						TextE.setCharacterSize(dim::EventTextSize_Week);
						TextE.setFillColor(sf::Color::Black);

						TextEE.setFont(dim::font);
						TextEE.setCharacterSize(dim::EventTextSize_Week);
						TextEE.setFillColor(sf::Color::Black);


						ItemE.setSize(dim::SizeOfEventTextBox_Week);
						ItemE.setFillColor(sf::Color::Green);

						sf::Vector2f position;

						for (int i = 0; i < EventList.size(); i++) {

							position = dim::ItemOffset_Week + sf::Vector2f(X*dim::OffestBetweenItems_Week.x + dim::EventTextOffset_Week.x,
								(i + 1)*dim::SizeOfEventTextBox_Week.y + (i + 1)*dim::EventTextOffset_Week.y);

							ItemE.setPosition(position);

							TextE.setPosition(position + dim::TextOffset_Day);
							TextE.setString(EventList.at(i)->DurationDescription());


							TextEE.setPosition(position + dim::TextNameEventOffset_Week);
							TextEE.setString(EventList.at(i)->EventDescription());

							window.draw(ItemE);
							window.draw(TextE);
							window.draw(TextEE);

						}


					}

				}


				sf::Vector2f position = sf::Vector2f(dim::ItemOffset_Week.x + X * (dim::OffestBetweenItems_Week.x),
					dim::ItemOffset_Week.y);


				Text.setString(std::to_string(CountNumberOfDays));
				Item.setPosition(position);
				Text.setPosition(position + dim::TextOffset_Month);
				CountNumberOfDays++;

				window.draw(Item);
				window.draw(Text);
			}
		}


		Item.setSize(dim::SizeOfButton);
		Item.setOutlineThickness(dim::OutlineThickness_Button);
		Item.setPosition(dim::ButtonOffset);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineColor(sf::Color::White);

		Text.setPosition(dim::ButtonOffset + dim::TextOffset_Button);
		Text.setFillColor(sf::Color::White);
		Text.setCharacterSize(dim::TextSize_Calendar);
		Text.setString("Add Event");

		window.draw(Item);
		window.draw(Text);

	}


	Day* doTheyIntersect_Week(sf::Vector2f mPosition) {


		int CountNumberOfDays = FirstDayOfMonth + Week * 7;

		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfItem_Week);

		for (int X = 0; (X < 7 && CountNumberOfDays <= NumberOfDaysInMonth); X++) {


			if ((X >= FirstDayOfMonth && Week == 0) || Week > 0) {



				sf::Vector2f position = sf::Vector2f(dim::ItemOffset_Week.x + X * (dim::OffestBetweenItems_Week.x),
					dim::ItemOffset_Week.y);

				Item.setPosition(position);

				if (Item.getGlobalBounds().contains(mPosition)) {

					return Days.at(CountNumberOfDays);
				}
				CountNumberOfDays++;
			}
		}

		return NULL;
	}

public:
	std::vector<Day*> Days;


	Month(int monthNumber, int year) :Name(dim::MonthNames.at(monthNumber)), Number(monthNumber), // monthNumber+1??
		NumberOfDaysInMonth(NumberOfDays(monthNumber, year)), FirstDayOfMonth(DayNumber(1, monthNumber+1, year))
	{

		int Counter = FirstDayOfMonth;


		for (int i = 0; i < NumberOfDaysInMonth; i++)
		{
			Day* dayToAdd = new Day(Counter);

			Counter++;

			if (Counter == 7)
			{
				Counter = 0;
			}
			Days.push_back(dayToAdd);

		}
	};


	void displayMonth() {


		if (Week != -1) {

			displayWeek();
			return;
		}

		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfItem_Month);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineThickness(dim::OutlineThickness_Month);


		sf::Text Text;

		Text.setFont(dim::font);
		Text.setFillColor(sf::Color::White);
		Text.setCharacterSize(dim::TextSize_Month);


		for (int i = 0; i < 7; i++) {

			Text.setPosition(dim::DayNamesOffset + sf::Vector2f(i*dim::OffestBetweenItems_Month.x, 0));
			Text.setString(dim::DayNames.at(i));

			window.draw(Text);
		}


		int CountNumberOfDays = 1;

		for (int Y = 0; Y * 7 <= NumberOfDaysInMonth; Y++) {

			for (int X = 0; (X < 7 && CountNumberOfDays <= NumberOfDaysInMonth); X++) {

				Item.setSize(dim::SizeOfItem_Month);

				if ((X >= FirstDayOfMonth && Y == 0) || Y > 0) {


					if (Days.at(CountNumberOfDays-1)->HaveAnyEvent()) {

						Item.setFillColor(sf::Color(130, 0, 0));
					}
					else {

						Item.setFillColor(sf::Color::Transparent);
					}


					sf::Vector2f position = sf::Vector2f(dim::ItemOffset_Month.x + X * (dim::OffestBetweenItems_Month.x),
						dim::ItemOffset_Month.y + Y * (dim::OffestBetweenItems_Month.y));

					Item.setPosition(position);
					Text.setPosition(position + dim::TextOffset_Month);

					Text.setString(std::to_string(CountNumberOfDays));
					CountNumberOfDays++;

					window.draw(Item);
					Item.setFillColor(sf::Color::Transparent);
					window.draw(Text);
				}
			}

			Item.setSize(sf::Vector2f(dim::SizeOfItem_Month.x / 2, dim::SizeOfItem_Month.y));
			Item.setPosition(sf::Vector2f(dim::ItemOffset_Month.x - dim::OffestBetweenItems_Month.x/2, dim::ItemOffset_Month.y + Y * (dim::OffestBetweenItems_Month.y)));

			window.draw(Item);

		}


		Item.setSize(dim::SizeOfButton);
		Item.setOutlineThickness(dim::OutlineThickness_Button);
		Item.setPosition(dim::ButtonOffset);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineColor(sf::Color::White);

		Text.setPosition(dim::ButtonOffset + dim::TextOffset_Button);
		Text.setFillColor(sf::Color::White);
		Text.setCharacterSize(dim::TextSize_Calendar);
		Text.setString("Add Event");

		window.draw(Item);
		window.draw(Text);


	}


	Day* doTheyIntersect_Month(sf::Vector2f mPosition) {

		if (Week != -1) {

			return doTheyIntersect_Week(mPosition);
		}

		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfItem_Month);

		int CountNumberOfDays = 1;


		for (int Y = 0; Y * 7 <= NumberOfDaysInMonth; Y++) {

			for (int X = 0; (X < 7 && CountNumberOfDays <= NumberOfDaysInMonth); X++) {

				if ((X >= FirstDayOfMonth && Y == 0) || Y > 0) {


					sf::Vector2f position = sf::Vector2f(dim::ItemOffset_Month.x + X * (dim::OffestBetweenItems_Month.x),
														dim::ItemOffset_Month.y + Y * (dim::OffestBetweenItems_Month.y));

					Item.setPosition(position);

					if (Item.getGlobalBounds().contains(mPosition)) {

						return Days.at(CountNumberOfDays-1);
					}

					CountNumberOfDays++;
				}
			}

			Item.setSize(sf::Vector2f(dim::SizeOfItem_Month.x / 2, dim::SizeOfItem_Month.y));
			Item.setPosition(sf::Vector2f(dim::ItemOffset_Month.x - dim::OffestBetweenItems_Month.x / 2, dim::ItemOffset_Month.y + Y * (dim::OffestBetweenItems_Month.y)));

			if (Item.getGlobalBounds().contains(mPosition)) {

				Week = Y;
				return NULL;
			}
		}

		return NULL;
	}


	bool isAddNewEventPressed(sf::Vector2f mPosition) {

		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfButton);
		Item.setPosition(dim::ButtonOffset);

		if (Item.getGlobalBounds().contains(mPosition)) {

			return true;
		}

		return false;
	}

	bool moveBack() {

		if (Week == -1) {

			return true;
		}
		else {

			Week = -1;
			return false;
		}
	}

	~Month() {};

};