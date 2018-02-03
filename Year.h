#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Dimensions.h"
#include "Month.h"

extern sf::RenderWindow window;

class Year {

	const int YearNumber;

public:
	std::vector<Month*> Months;

	Year(int mYear) :YearNumber(mYear) {
		for (int i = 0; i < 12; i++)
		{

			Month* monthToAdd = new Month(i, mYear);
			Months.push_back(monthToAdd);
		}
	}

	void displayYear() {

		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfItem_Year);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineThickness(dim::OutlineThickness_Year);
		Item.setOutlineColor(sf::Color::White);


		sf::Text NumberOfMonths_Text;

		NumberOfMonths_Text.setFont(dim::font);
		NumberOfMonths_Text.setFillColor(sf::Color::White);
		NumberOfMonths_Text.setCharacterSize(dim::TextSize_Year);


		for (int Y = 0; Y < 3; Y++) {

			for (int X = 0; X < 4; X++) {

				sf::Vector2f position = dim::ItemOffset_Year;
				position += sf::Vector2f(X*dim::OffsetBetweenItems_Year.x, Y*dim::OffsetBetweenItems_Year.y);

				Item.setPosition(position);
				NumberOfMonths_Text.setPosition(position + dim::TextOffset_Year);

				NumberOfMonths_Text.setString(dim::MonthNames.at(Y * 4 + X));

				window.draw(Item);
				window.draw(NumberOfMonths_Text);

				int CountNumberOfDays = 1;
			

			}
		}

		Item.setSize(dim::SizeOfButton);
		Item.setOutlineThickness(dim::OutlineThickness_Button);
		Item.setPosition(dim::ButtonOffset);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineColor(sf::Color::White);

		NumberOfMonths_Text.setPosition(dim::ButtonOffset + dim::TextOffset_Button);
		NumberOfMonths_Text.setFillColor(sf::Color::White);
		NumberOfMonths_Text.setCharacterSize(dim::TextSize_Calendar);
		NumberOfMonths_Text.setString("Add Event");

		window.draw(Item);
		window.draw(NumberOfMonths_Text);

	}

	Month* doTheyIntersect_Year(sf::Vector2f mPosition) {

		sf::RectangleShape Item;

		Item.setSize(dim::SizeOfItem_Year);

		for (int Y = 0; Y < 3; Y++) {

			for (int X = 0; X < 4; X++) {

				sf::Vector2f position = dim::ItemOffset_Year;
				position += sf::Vector2f(X*dim::OffsetBetweenItems_Year.x, Y*dim::OffsetBetweenItems_Year.y);

				Item.setPosition(position);

				if (Item.getGlobalBounds().contains(mPosition)) {

					return Months.at(Y * 4 + X);
				}
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

	int GetYearNumber()
	{
		return this->YearNumber;
	}

};
