#pragma once
#include <SFML\Graphics.hpp>
#include "Dimensions.h"
#include "Person.h"
#include <string>
#include <algorithm>
#include <vector>
#include "LongTermEvent.h"
#include "Year.h"

extern sf::RenderWindow window;

class EventHelper {


	//	Event
	std::string Day = "DD", Month = "MM", MYear = "YYYY", SHour = "HH", SMinutes = "mm", FirstName, SecondName;
	std::string Description = "Description";


	std::string EHour = "HH"; 
	std::string EMinutes = "mm"; 

	Person Man;		

	//	LongTernEvent
	std::string LastingTime;	

	//	PeriodicEvent
	std::string Period;	

	bool TypeOfEvent[2];
	bool ActiveInputBox[12];
	bool WithPerson = false;

	Event *ready = NULL;

	std::vector<Year*>* YearList;

	/*		Active input box			
	*
	*	0	-	Description
	*	1	-	Day
	*	2	-	Month
	*	3	-	Year
	*	4	-	FirstName
	*	5	-	SecondName
	*	6	-	LastingTime
	*	7	-	Period
	*	8	-	Hour
	*	9	-	Minutes
	*	10	-	EHour
	*	11	-	EMinutes
	*
	*/

public:

	EventHelper() {	};

	EventHelper(std::vector<Year*>* yearList)
	{
		
		YearList = yearList;
		
		TypeOfEvent[0] = false;
		TypeOfEvent[1] = false;

		for (int i = 0; i < 12; i++)
			ActiveInputBox[i] = false;

	}

	void display() {

		/*			Save Event Button													*/

		sf::RectangleShape Item;
		
		Item.setSize(dim::SizeOfButton);
		Item.setOutlineThickness(dim::OutlineThickness_Button);
		Item.setPosition(dim::ButtonOffset);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineColor(sf::Color::White);
		
		
		sf::Text Text;

		Text.setFont(dim::font);
		Text.setPosition(dim::ButtonOffset + dim::TextOffset_Button);
		Text.setFillColor(sf::Color::White);
		Text.setCharacterSize(dim::TextSize_Calendar);
		Text.setString("Save Event");

		window.draw(Item);
		window.draw(Text);

		/*			CheckBoxes															*/


		Item.setFillColor(sf::Color::Transparent);
		Item.setPosition(dim::CheckBoxOffset_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);
		Item.setOutlineThickness(dim::OutlineThickness_Helper);
		Item.setOutlineColor(sf::Color::White);

		Text.setPosition(dim::CheckBoxOffset_Helper + dim::CheckBoxTextOffset_Helper);
		Text.setFillColor(sf::Color::White);
		Text.setCharacterSize(dim::CheckBoxTextSize_Helper);

		Text.setString("Long term");

		if (TypeOfEvent[0] == true) {

			Item.setFillColor(sf::Color(130, 0, 0));
		}

		window.draw(Text);
		window.draw(Item);

		Item.setFillColor(sf::Color::Transparent);
		Item.setPosition(dim::CheckBoxOffset_Helper+dim::OffsetBetweekCheckBoxes_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);
		Item.setOutlineThickness(dim::OutlineThickness_Helper);
		Item.setOutlineColor(sf::Color::White);

		Text.setPosition(dim::CheckBoxOffset_Helper + dim::CheckBoxTextOffset_Helper + dim::OffsetBetweekCheckBoxes_Helper);

		Text.setString("Periodic");

		if (TypeOfEvent[1] == true) {

			Item.setFillColor(sf::Color(130, 0, 0));
		}

		window.draw(Text);
		window.draw(Item);


		Item.setFillColor(sf::Color::Transparent);
		Item.setPosition(dim::CheckBoxOffset_Helper + dim::OffsetBetweekCheckBoxes_Helper + dim::OffsetBetweekCheckBoxes_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);
		Item.setOutlineThickness(dim::OutlineThickness_Helper);
		Item.setOutlineColor(sf::Color::White);

		Text.setPosition(dim::CheckBoxOffset_Helper + dim::CheckBoxTextOffset_Helper + dim::OffsetBetweekCheckBoxes_Helper + dim::OffsetBetweekCheckBoxes_Helper);

		Text.setString("With person");

		if (WithPerson == true) {

			Item.setFillColor(sf::Color(130, 0, 0));
		}

		window.draw(Text);
		window.draw(Item);



		/*			Input Text Box														*/

		Item.setPosition(dim::DescriptionBoxOffset_Helper);
		Item.setSize(dim::SizeOfDescriptionBox_Helper);
		Item.setOutlineThickness(dim::OutlineThicknessDescriptionBox_Helper);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineColor(sf::Color::White);

		Text.setPosition(dim::DescriptionBoxOffset_Helper + dim::TextDescriptionBoxOffset_Helper);
		Text.setCharacterSize(dim::TextSizeDescriptionBox_Helper);
		Text.setString(Description);

		window.draw(Item);
		window.draw(Text);


		/*			DDMMYYYY															*/

		Item.setSize(dim::SizeOfDDMMYYYYBox_Helper);
		Item.setPosition(dim::DDMMYYYYBoxOffset_Helper);
		Item.setOutlineThickness(dim::OutlineThicknessDDMMYYYYBox_Helper);
		
		Text.setPosition(dim::DDMMYYYYBoxOffset_Helper + dim::TextDDMMYYYYBoxOffset_Helper);
		Text.setCharacterSize(dim::TextSizeDDMMYYYY_Helper);
		Text.setString(Day);

		window.draw(Item);
		window.draw(Text);


		Item.setSize(dim::SizeOfDDMMYYYYBox_Helper);
		Item.setPosition(dim::DDMMYYYYBoxOffset_Helper+dim::OffsetBetweenDDMMYYYYBoxes_Helper);

		Text.setPosition(dim::DDMMYYYYBoxOffset_Helper + dim::TextDDMMYYYYBoxOffset_Helper+dim::OffsetBetweenDDMMYYYYBoxes_Helper);
		Text.setCharacterSize(dim::TextSizeDDMMYYYY_Helper);
		Text.setString(Month);

		window.draw(Item);
		window.draw(Text);


		Item.setSize(sf::Vector2f(1.5 * dim::SizeOfDDMMYYYYBox_Helper.x, dim::SizeOfDDMMYYYYBox_Helper.y));
		Item.setPosition(dim::DDMMYYYYBoxOffset_Helper + dim::OffsetBetweenDDMMYYYYBoxes_Helper + dim::OffsetBetweenDDMMYYYYBoxes_Helper);

		Text.setPosition(dim::DDMMYYYYBoxOffset_Helper + dim::TextDDMMYYYYBoxOffset_Helper + dim::OffsetBetweenDDMMYYYYBoxes_Helper + dim::OffsetBetweenDDMMYYYYBoxes_Helper);
		Text.setCharacterSize(dim::TextSizeDDMMYYYY_Helper);
		Text.setString(MYear);

		window.draw(Item);
		window.draw(Text);

		/*			HH MM																*/


		Item.setSize(dim::SizeOfHHMMBox_Helper);
		Item.setPosition(dim::HHMMBoxOffset_Helper);
		Item.setOutlineThickness(dim::OutlineThicknessHHMMBox_Helper);

		Text.setPosition(dim::HHMMBoxOffset_Helper + dim::TextHHMMBoxOffset_Helper);
		Text.setCharacterSize(dim::TextSizeHHMM_Helper);
		Text.setString(SHour);

		window.draw(Item);
		window.draw(Text);

		Item.setSize(dim::SizeOfHHMMBox_Helper);
		Item.setPosition(dim::HHMMBoxOffset_Helper + dim::OffsetBetweenHHMMBoxes_Helper);

		Text.setPosition(dim::HHMMBoxOffset_Helper + dim::TextHHMMBoxOffset_Helper + dim::OffsetBetweenHHMMBoxes_Helper);
		Text.setCharacterSize(dim::TextSizeHHMM_Helper);
		Text.setString(SMinutes);

		window.draw(Item);
		window.draw(Text);
		 
		//	Ending
		
		Item.setSize(dim::SizeOfHHMMBox_Helper);
		Item.setPosition(dim::EndingHHMMBoxOffset_Helper);
		Item.setOutlineThickness(dim::OutlineThicknessHHMMBox_Helper);

		Text.setPosition(dim::EndingHHMMBoxOffset_Helper + dim::TextHHMMBoxOffset_Helper);
		Text.setCharacterSize(dim::TextSizeHHMM_Helper);
		Text.setString(EHour);

		window.draw(Item);
		window.draw(Text);

		Item.setSize(dim::SizeOfHHMMBox_Helper);
		Item.setPosition(dim::EndingHHMMBoxOffset_Helper + dim::OffsetBetweenHHMMBoxes_Helper);

		Text.setPosition(dim::EndingHHMMBoxOffset_Helper + dim::TextHHMMBoxOffset_Helper + dim::OffsetBetweenHHMMBoxes_Helper);
		Text.setCharacterSize(dim::TextSizeHHMM_Helper);
		Text.setString(EMinutes);

		window.draw(Item);
		window.draw(Text);



		/*			Periodic															*/

		if (TypeOfEvent[1]) {

			Text.setPosition(dim::InfoTextOffset_Helper);
			Text.setString("Period  -  Number of repetitions");
			
			window.draw(Text);


			Item.setSize(dim::SizeOfPeriodicBox_Helper);
			Item.setPosition(dim::PeriodicBoxOffset_Helper);
			Item.setOutlineThickness(dim::OutlineThicknessPeriodicBox_Helper);

			Text.setPosition(dim::PeriodicBoxOffset_Helper + dim::TextPeriodicBoxOffset_Helper);
			Text.setCharacterSize(dim::TextSizePeriodic_Helper);
			Text.setString(Period);

			window.draw(Item);
			window.draw(Text);


			Item.setSize(sf::Vector2f(1.5 * dim::SizeOfPeriodicBox_Helper.x, dim::SizeOfPeriodicBox_Helper.y));
			Item.setPosition(dim::PeriodicBoxOffset_Helper + dim::OffsetBetweenPeriodicBoxes_Helper);

			Text.setPosition(dim::PeriodicBoxOffset_Helper + dim::OffsetBetweenPeriodicBoxes_Helper + dim::TextPeriodicBoxOffset_Helper);
			Text.setCharacterSize(dim::TextSizePeriodic_Helper);
			Text.setString(LastingTime);

			window.draw(Item);
			window.draw(Text);
		}


		/*			LongTerm															*/

		if (TypeOfEvent[0]) {


			Text.setPosition(dim::InfoTextOffset_Helper);
			Text.setString("How many days");

			window.draw(Text);

			Item.setSize(sf::Vector2f(1.5 * dim::SizeOfPeriodicBox_Helper.x, dim::SizeOfPeriodicBox_Helper.y));
			Item.setPosition(dim::PeriodicBoxOffset_Helper);
			Item.setOutlineThickness(dim::OutlineThicknessPeriodicBox_Helper);
			Item.setOutlineColor(sf::Color::White);

			Text.setPosition(dim::PeriodicBoxOffset_Helper + dim::TextPeriodicBoxOffset_Helper);
			Text.setCharacterSize(dim::TextSizePeriodic_Helper);
			Text.setString(LastingTime);

			window.draw(Item);
			window.draw(Text);
		}

		/*			Person																*/

		if (WithPerson) {

			Text.setPosition(dim::InfoPersonTextOffset_Helper);
			Text.setString("First name \t\t\t Second Name");

			window.draw(Text);

			Item.setSize(dim::SizeOfPersonBox_Helper);
			Item.setPosition(dim::PersonBoxOffset_Helper);
			Item.setOutlineThickness(dim::OutlineThicknessPersonBox_Helper);

			Text.setPosition(dim::PersonBoxOffset_Helper + dim::TextPersonBoxOffset_Helper);
			Text.setCharacterSize(dim::TextSizePerson_Helper);
			Text.setString(FirstName);

			window.draw(Item);
			window.draw(Text);


			Item.setPosition(dim::PersonBoxOffset_Helper + dim::OffsetBetweenPersonBoxes_Helper);

			Text.setPosition(dim::PersonBoxOffset_Helper + dim::OffsetBetweenPersonBoxes_Helper + dim::TextPersonBoxOffset_Helper);
			Text.setCharacterSize(dim::TextSizePerson_Helper);
			Text.setString(SecondName);

			window.draw(Item);
			window.draw(Text);
		}


	}

	bool intersection(sf::Vector2f mousePos) {

		sf::RectangleShape Item;


		Item.setSize(dim::SizeOfButton);
		Item.setPosition(dim::ButtonOffset);

		if (Item.getGlobalBounds().contains(mousePos)) {

			createEvent();
			return true;	//	if event was created correctly
		}


		Item.setPosition(dim::CheckBoxOffset_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);


		if (Item.getGlobalBounds().contains(mousePos)) {

			if (TypeOfEvent[0] == true) {

				TypeOfEvent[0] = !TypeOfEvent[0];
				Period.clear();
				LastingTime.clear();
			}
			else if(TypeOfEvent[0] == false) {

				TypeOfEvent[0] = true;
				TypeOfEvent[1] = false;
				Period.clear();
				LastingTime.clear();
			}

			return false;
		}

		Item.setPosition(dim::CheckBoxOffset_Helper + dim::OffsetBetweekCheckBoxes_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			if (TypeOfEvent[1] == true) {

				TypeOfEvent[1] = !TypeOfEvent[1];
				Period.clear();
				LastingTime.clear();
			}
			else if (TypeOfEvent[1] == false) {

				TypeOfEvent[1] = true;
				TypeOfEvent[0] = false;
				Period.clear();
				LastingTime.clear();
			}
			return false;
		}


		Item.setPosition(dim::CheckBoxOffset_Helper + dim::OffsetBetweekCheckBoxes_Helper + dim::OffsetBetweekCheckBoxes_Helper);
		Item.setSize(dim::SizeOfCheckBox_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			WithPerson = !WithPerson;
			FirstName.clear();
			SecondName.clear();
			return false;
		}


		//	Check if DescriptionBox Selected

		Item.setPosition(dim::DescriptionBoxOffset_Helper);
		Item.setSize(dim::SizeOfDescriptionBox_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[0] = true;
			return false;
		}
		else {

			ActiveInputBox[0] = false;
		}


		Item.setSize(dim::SizeOfDDMMYYYYBox_Helper);
		Item.setPosition(dim::DDMMYYYYBoxOffset_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[1] = true;
			return false;
		}
		else {

			ActiveInputBox[1] = false;
		}


		Item.setPosition(dim::DDMMYYYYBoxOffset_Helper + dim::OffsetBetweenDDMMYYYYBoxes_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[2] = true;
			return false;
		}
		else {

			ActiveInputBox[2] = false;
		}

		Item.setSize(sf::Vector2f(1.5 * dim::SizeOfDDMMYYYYBox_Helper.x, dim::SizeOfDDMMYYYYBox_Helper.y));
		Item.setPosition(dim::DDMMYYYYBoxOffset_Helper + dim::OffsetBetweenDDMMYYYYBoxes_Helper + dim::OffsetBetweenDDMMYYYYBoxes_Helper);
		
		if (Item.getGlobalBounds().contains(mousePos)) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[3] = true;
			return false;
		}
		else {

			ActiveInputBox[3] = false;
		}


		Item.setSize(dim::SizeOfHHMMBox_Helper);
		Item.setPosition(dim::HHMMBoxOffset_Helper);


		if (Item.getGlobalBounds().contains(mousePos)) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[8] = true;
			return false;
		}
		else {

			ActiveInputBox[8] = false;
		}


		Item.setSize(dim::SizeOfHHMMBox_Helper);
		Item.setPosition(dim::HHMMBoxOffset_Helper + dim::OffsetBetweenHHMMBoxes_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[9] = true;
			return false;
		}
		else {

			ActiveInputBox[9] = false;
		}


		Item.setSize(dim::SizeOfHHMMBox_Helper);
		Item.setPosition(dim::EndingHHMMBoxOffset_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[10] = true;
			return false;
		}
		else {

			ActiveInputBox[10] = false;
		}


		Item.setSize(dim::SizeOfHHMMBox_Helper);
		Item.setPosition(dim::EndingHHMMBoxOffset_Helper+dim::OffsetBetweenHHMMBoxes_Helper);

		if (Item.getGlobalBounds().contains(mousePos)) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[11] = true;
			return false;
		}
		else {

			ActiveInputBox[11] = false;
		}

		Item.setSize(dim::SizeOfPeriodicBox_Helper);
		Item.setPosition(dim::PeriodicBoxOffset_Helper);

		if (Item.getGlobalBounds().contains(mousePos) && TypeOfEvent[1]) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[7] = true;
			return false;
		}
		else {

			ActiveInputBox[7] = false;
		}


		Item.setSize(sf::Vector2f(1.5 * dim::SizeOfPeriodicBox_Helper.x, dim::SizeOfPeriodicBox_Helper.y));
		Item.setPosition(dim::PeriodicBoxOffset_Helper + dim::OffsetBetweenPeriodicBoxes_Helper);

		if (Item.getGlobalBounds().contains(mousePos) && TypeOfEvent[1]) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[6] = true;
			return false;
		}
		else {

			ActiveInputBox[6] = false;
		}


		Item.setSize(sf::Vector2f(1.5 * dim::SizeOfPeriodicBox_Helper.x, dim::SizeOfPeriodicBox_Helper.y));
		Item.setPosition(dim::PeriodicBoxOffset_Helper);

		if (Item.getGlobalBounds().contains(mousePos) && TypeOfEvent[0]) {

			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[6] = true;
			return false;
		}
		else if (TypeOfEvent[0]) {

			ActiveInputBox[6] = false;
		}


		Item.setSize(dim::SizeOfPersonBox_Helper);
		Item.setPosition(dim::PersonBoxOffset_Helper);

		if (Item.getGlobalBounds().contains(mousePos) && WithPerson) {
			
			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[4] = true;
			return false;
		}
		else if (WithPerson) {

			ActiveInputBox[4] = false;
		}

		Item.setPosition(dim::PersonBoxOffset_Helper + dim::OffsetBetweenPersonBoxes_Helper);
		
		if (Item.getGlobalBounds().contains(mousePos) && WithPerson) {
			
			for (int i = 0; i < 12; i++)
				ActiveInputBox[i] = false;

			ActiveInputBox[5] = true;
			return false;
		}
		else if (WithPerson) {

			ActiveInputBox[5] = false;
		}

		return false;

	}

	void enterChar(int c) {

		/*		Active input box
		*
		*	0	-	Description
		*	1	-	Day
		*	2	-	Month
		*	3	-	Year
		*	4	-	First Name
		*	5	-	Second Name
		*	6	-	LastingTime
		*	7	-	Period
		*
		*/

		char add=-1;

		if (c <= 25) {

			add = 0;
			add = (char)c + 65;
		}
		else if (c > 25 && c <= 35) {

			add = (char)c + 22;
		}
		else if (c == 57) {

			add = -3;
		}
		else if (c == 59) {

			add = -2;	//backspace
		}

		if (ActiveInputBox[0]) {

			if (Description == "Description") {

				Description.clear();
			}

			if (add >=0)

				if (Description.length() < 25) {

					Description += add;
				}
			if (add == -2) {

				Description = Description.substr(0, Description.size() - 1);
			}
			if (add == -3) {

				if (Description.length() < 25) {

					Description += " ";
				}
			}
		}
		if (ActiveInputBox[1]) {

			if (Day == "DD") {
				
				Day.clear();
			}

			if (add > 26) {
				
				if (Day.length() < 2) {

					Day += add;
				}
			}
			if (add == -2) {

				Day = Day.substr(0, Day.size() - 1);
			}
			if (add == -3) {

				if (Day.length() < 2) {

					Day += " ";
				}
			}

		}
		if (ActiveInputBox[2]) {

			if (Month == "MM") {
				
				Month.clear();
			}

			if (add > 26) {

				if (Month.length() < 2) {

					Month += add;
				}
			}
			if (add == -2) {

				Month = Month.substr(0, Month.size() - 1);
			}
			if (add == -3) {
				
				if (Month.length() < 2) {

					Month += " ";
				}
			}

		}
		if (ActiveInputBox[3]) {

			if (MYear == "YYYY") {

				MYear.clear();
			}

			if (add > 26) {
				
				if (MYear.length() < 4) {

					MYear += add;
				}
			}
			if (add == -2) {

				MYear = MYear.substr(0, MYear.size() - 1);
			}
			if (add == -3) {

				if (MYear.length() < 4) {

					MYear += " ";
				}
			}

		}
		if (ActiveInputBox[4]) {

			if (add > 26) {

				if (FirstName.length() < 9) {
				
					FirstName += add;
				}
			}
			if (add == -2) {

				FirstName = FirstName.substr(0, FirstName.size() - 1);
			}
			if (add == -3) {

				if (FirstName.length() < 9) {
				
					FirstName += " ";
				}
			}

		}
		if (ActiveInputBox[5]) {

			if (add > 26) {

				if (SecondName.length() < 9) {
				
					SecondName += add;
				}
			}
			if (add == -2) {

				SecondName = SecondName.substr(0, SecondName.size() - 1);
			}
			if (add == -3) {

				if (SecondName.length() < 9) {
				
					SecondName += " ";
				}
			}

		}
		if (ActiveInputBox[6]) {

			if (add > 26) {

				if (LastingTime.length() < 4) {

					LastingTime += add;
				}
			}
			if (add == -2) {

				LastingTime = LastingTime.substr(0, LastingTime.size() - 1);
			}
			if (add == -3) {
				
				if (LastingTime.length() < 4) {
				
					LastingTime += " ";
				}
			}

		}
		if (ActiveInputBox[7]) {

			if (add > 26) {

				if (Period.length() < 2) {
				
					Period += add;
				}
			}
			if (add == -2) {

				Period = Period.substr(0, Period.size() - 1);
			}
			if (add == -3) {
				
				if (Period.length() < 2) {

					Period += " ";
				}
			}

		}
		if (ActiveInputBox[8]) {

			if (add > 26) {

				if (SHour == "HH") {
					
					SHour.clear();
				}

				if (SHour.length() < 2) {

					SHour += add;
				}
			}
			if (add == -2) {

				SHour = SHour.substr(0, SHour.size() - 1);
			}
			if (add == -3) {

				if (SHour.length() < 2) {

					SHour += " ";
				}
			}

		}
		if (ActiveInputBox[9]) {

			if (SMinutes == "mm") {

				SMinutes.clear();
			}

			if (add > 26) {

				if (SMinutes.length() < 2) {

					SMinutes += add;
				}
			}
			if (add == -2) {

				SMinutes = SMinutes.substr(0, SMinutes.size() - 1);
			}
			if (add == -3) {

				if (SMinutes.length() < 2) {

					SMinutes += " ";
				}
			}

		}
		if (ActiveInputBox[10]) {

			if (EHour == "HH") {

				EHour.clear();
			}

			if (add > 26) {

				if (EHour.length() < 2) {

					EHour += add;
				}
			}
			if (add == -2) {

				EHour = EHour.substr(0, EHour.size() - 1);
			}
			if (add == -3) {

				if (EHour.length() < 2) {

					EHour += " ";
				}
			}

		}
		if (ActiveInputBox[11]) {

			if (EMinutes == "mm") {

				EMinutes.clear();
			}

			if (add > 26) {

				if (EMinutes.length() < 2) {

					EMinutes += add;
				}
			}
			if (add == -2) {

				EMinutes = EMinutes.substr(0, EMinutes.size() - 1);
			}
			if (add == -3) {

				if (EMinutes.length() < 2) {

					EMinutes += " ";
				}
			}

		}

	}
	
	bool createEvent() 
	{
		
		try
		{
			int nrDay = std::stoi(this->Day);
			int nrMonth = std::stoi(this->Month);
			int nrYear = std::stoi(this->MYear);
			int nrStartingTime = std::stoi(this->SHour);
			int nrEndingTime = std::stoi(this->EHour); 



			int actualDay = nrDay - 1;
			int actualMonth = nrMonth - 1;
			int actualYear = nrYear - 2017;

			if (nrDay >= 1 && nrDay <= 30 && nrMonth >= 1 && nrMonth <= 12 && nrYear >= 2017 && nrYear <= 2020)
			{
				if (TypeOfEvent[0])
				{
					int nrLastingTime = std::stoi(this->LastingTime);
					

					auto lastDay = YearList->at(actualYear)->Months.at(actualMonth)->Days.back();
					Event* eventToAdd = new LongTermEvent(nrStartingTime, nrEndingTime, Description, Person(FirstName,SecondName), nrLastingTime);
					for (int i = 0; i < nrLastingTime; i++)
					{
						YearList->at(actualYear)->Months.at(actualMonth)->Days.at(actualDay)->AddEvent(eventToAdd);
						if (YearList->at(actualYear)->Months.at(actualMonth)->Days.at(actualDay) == lastDay)
						{
							actualMonth++;
							actualDay = 0;
						}
						else
						{
							actualDay++;
						}
					}
				}
				//periodic
				else if (TypeOfEvent[1])
				{
					int nrLastingTime = std::stoi(this->LastingTime);
					int nrPeroidTime = std::stoi(this->Period);

					

					auto lastDay = YearList->at(actualYear)->Months.at(actualMonth)->Days.back();
					
					Event* eventToAdd = new PeriodicEvent(nrStartingTime, nrEndingTime, Description, Person(FirstName, SecondName), nrPeroidTime, nrLastingTime);

					auto nrOfDays = YearList->at(actualYear)->Months.at(actualMonth)->Days.size();

					for (int i = 0; i < nrLastingTime; i++)
					{
						if (nrOfDays < actualDay)
						{
							actualMonth++;
							actualDay = actualDay - nrOfDays;
						}

						YearList->at(actualYear)->Months.at(actualMonth)->Days.at(actualDay)->AddEvent(eventToAdd);

						if (YearList->at(actualYear)->Months.at(actualMonth)->Days.at(actualDay) == lastDay)
						{
							actualMonth++;
							actualDay = 0;
						}
						else
						{
							actualDay = actualDay + nrPeroidTime;
						}
					}
				}
				//normal
				else
				{
					Event* eventToAdd = new Event(nrStartingTime, nrEndingTime, Description, Person(FirstName, SecondName));
					YearList->at(actualYear)->Months.at(actualMonth)->Days.at(actualDay)->AddEvent(eventToAdd);
				}

				return true;
			}

			else
			{
				return false;
			}			
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what();
			return false;
		}
	}

	
};
