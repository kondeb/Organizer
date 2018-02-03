#pragma once
#include "Event.h"
#include <string>
#include <list>
#include <iostream>
#include "PeriodicEvent.h"
#include <vector>

extern sf::RenderWindow window;

class Day
{
private:
	bool IsHourFree(Event* eventToAdd)
	{
		if (EventList.size() == 0)
			return true;
		else
		{
			for (auto &temp : EventList)
			{
				auto startingTime = temp->GetStartingTime();
				auto endingTime = temp->GetEndingTime();

				if ((eventToAdd->GetStartingTime() >= startingTime && eventToAdd->GetStartingTime() <= endingTime) || (eventToAdd->GetEndingTime() >= startingTime && eventToAdd->GetEndingTime() <= endingTime))
					return false;
				else
					return true;
			}
		}
		
	}

	std::vector<Event*> EventList;
	const std::string NameOfDay;
	const int DayNumber;

	void SortEvents()
	{
		std::sort(this->EventList.begin(), this->EventList.end());
	}

public:

	std::vector<Event*> returnEventList(){

		return EventList;
	}


	Day(int dayNumber) : NameOfDay(dim::DayNames.at(dayNumber)), DayNumber(dayNumber) { 	};


	~Day() { }

	std::vector<Event*> GetEvents()
	{
		return this->EventList;
	}

	void AddEvent(Event* eventToAdd)
	{
		try
		{
			if (IsHourFree(eventToAdd))
			{
				EventList.push_back(eventToAdd);
				SortEvents();
			}
		}
		catch (const std::exception& ex)
		{
			std::cout << "error occured durning adding event" << ex.what() << std::endl;
		}
	};

	void RemoveEvent(Event* eventToRemove)
	{
		auto tempList = this->EventList;
		try
		{
			tempList.erase(std::remove(tempList.begin(), tempList.end(), eventToRemove), tempList.end());
			this->EventList = tempList;
		}
		catch (const std::exception& ex)
		{
			std::cout << "error occured durning removing event" << ex.what() << std::endl;
		}
	}

	bool HaveAnyEvent()
	{
		if (EventList.size() == 0)
			return false;
		else
			return true;
	};

	void display_Day() {


		sf::RectangleShape Item;


		sf::Text EventName;
		EventName.setPosition(dim::NoEventsTextPosition_Day);
		EventName.setFont(dim::font);
		EventName.setCharacterSize(dim::NoEventTextSize_Day);
		EventName.setFillColor(sf::Color::White);

		if (EventList.empty()) {

			EventName.setString("No events");

			window.draw(EventName);
		}
		else {

			//EventName.setString()

			EventName.setCharacterSize(dim::EventTextSize_Day);
			EventName.setFillColor(sf::Color::Black);


			Item.setSize(dim::SizeOfItem_Day);
			Item.setFillColor(sf::Color::Green);

			sf::Text EventTime;

			EventTime.setFont(dim::font);
			EventTime.setCharacterSize(dim::EventTextSize_Day);
			EventTime.setFillColor(sf::Color::Black);

			sf::Vector2f position;

			for (int i = 0; i < EventList.size(); i++) {

				position = dim::ItemOffset_Day + sf::Vector2f(0, i*dim::OffsetBetweenItems_Day.y);

				Item.setPosition(position);
				EventTime.setPosition(position + dim::TextOffset_Day);
				EventName.setPosition(position + dim::TextOffset_Day + dim::TextNameEventOffset_Day);

				EventTime.setString(EventList.at(i)->DurationDescription());
				EventName.setString(EventList.at(i)->EventDescription());

				window.draw(Item);
				window.draw(EventTime);
				window.draw(EventName);
			}



		}

			Item.setSize(dim::SizeOfButton);
			Item.setOutlineThickness(dim::OutlineThickness_Button);
			Item.setPosition(dim::ButtonOffset);
			Item.setFillColor(sf::Color::Transparent);
			Item.setOutlineColor(sf::Color::White);

			EventName.setPosition(dim::ButtonOffset + dim::TextOffset_Button);
			EventName.setFillColor(sf::Color::White);
			EventName.setCharacterSize(dim::TextSize_Calendar);
			EventName.setString("Add Event");

			window.draw(Item);
			window.draw(EventName);

	}

	int returnDayNumber() {

		return DayNumber;
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
};