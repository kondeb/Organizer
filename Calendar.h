#define _CRT_SECURE_NO_WARNINGS

#pragma once
#include "Year.h"
#include <time.h>

extern sf::RenderWindow window;

class Calendar {

	/*			Variables used to display items				*/


	std::vector<Year*> YearList;

	int BeginYear;


public:

	Calendar() {

		//	Load font
		try {
			if (!dim::font.loadFromFile("arial.ttf")) {

				throw "Error. Cannot load font !";
			}
		}
		catch (char *e) {

			std::cout << e;
		}


		//	Get current Year
		
		time_t theTime = time(NULL);
		struct tm *aTime = localtime(&theTime);

		BeginYear = aTime->tm_year + 1899;


		for (int i = BeginYear; i < BeginYear+3; i++) {

			YearList.push_back(new Year(i));
		}

	}

	std::vector<Year*>* GetYearList()
	{
		return &YearList;
	}


	void display_Calendar() {


		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfItem_Calendar);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineThickness(5);
		

		sf::Text NumberOfYears_Text;

		NumberOfYears_Text.setFont(dim::font);
		NumberOfYears_Text.setCharacterSize(dim::TextSize_Calendar);
		NumberOfYears_Text.setFillColor(sf::Color::White);


		
				
		sf::Color to_alpha = sf::Color::White;
		to_alpha.a = 135;


		for (int i = 0; i < 3 ; i++) {

			sf::Vector2f position = dim::ItemOffset_Calendar + sf::Vector2f(i*dim::OffsetBetweenItems_Calendar.x,0);

			Item.setPosition(position);

			NumberOfYears_Text.setPosition(position + dim::TextOffset_Calendar);
			NumberOfYears_Text.setString(std::to_string(BeginYear + i));


			if (i == 0 || i == 2 ) {

				NumberOfYears_Text.setFillColor(to_alpha);
				Item.setOutlineColor(to_alpha);
			}
			else {

				NumberOfYears_Text.setFillColor(sf::Color::White);
				Item.setOutlineColor(sf::Color::White);
			}

			window.draw(Item);
			window.draw(NumberOfYears_Text);
		}
		
		//	Draws black bar around screen

		sf::Vector2f SizeOfBlackOutliner = (sf::Vector2f) dim::WindowSize - sf::Vector2f(2 * dim::ThicknessOfBlackOutliner, 2*dim::ThicknessOfBlackOutliner);

		Item.setPosition(sf::Vector2f(dim::ThicknessOfBlackOutliner, dim::ThicknessOfBlackOutliner));
		Item.setSize(SizeOfBlackOutliner);
		Item.setOutlineThickness(dim::ThicknessOfBlackOutliner);
		Item.setOutlineColor(sf::Color::Black);
		Item.setFillColor(sf::Color::Transparent);

		window.draw(Item);

		//AddEvent Button 

		Item.setSize(dim::SizeOfButton);
		Item.setOutlineThickness(dim::OutlineThickness_Button);
		Item.setPosition(dim::ButtonOffset);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineColor(sf::Color::White);

		NumberOfYears_Text.setPosition(dim::ButtonOffset + dim::TextOffset_Button);
		NumberOfYears_Text.setFillColor(sf::Color::White);
		NumberOfYears_Text.setString("Add Event");

		window.draw(Item);
		window.draw(NumberOfYears_Text);
	}


	Year* doTheyIntersect_Calendar (sf::Vector2f  mPosition) {

		sf::RectangleShape Item;
		Item.setSize(dim::SizeOfItem_Calendar);

		sf::Vector2f position;

		for (int i = 0; i <= YearList.size(); i++) {

			position = dim::ItemOffset_Calendar + sf::Vector2f(i*dim::OffsetBetweenItems_Calendar.x,0);
			
			Item.setPosition(position);

			if (Item.getGlobalBounds().contains(mPosition)) {

				return YearList.at(i);
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

};