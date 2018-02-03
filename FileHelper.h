#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Calendar.h"

class FileHelper
{
public:
	FileHelper(std::vector<Year*>* yearList)
	{
		this->YearList = yearList;
	};

	FileHelper();
	~FileHelper();

	void SaveData()
	{

		myFile.open("test.txt", std::fstream::out | std::fstream::trunc);
	
		for (int a = 0; a < 3; a++)
		{
			std::string yearNumber = std::to_string(YearList->at(a)->GetYearNumber());
			for (int i = 0; i < 12; i++)
			{
				auto nrOfDays = YearList->at(a)->Months.at(i)->Days.size();
				std::string monthNumber = std::to_string(i);
				for (int j = 0; j < nrOfDays; j++)
				{
					std::string dayNumber = std::to_string(j);
					auto allEvents = YearList->at(a)->Months.at(i)->Days.at(j)->GetEvents();
					for (auto &event : allEvents)
					{
						std::string endingTime = std::to_string(event->GetEndingTime());
						std::string startingTime = std::to_string(event->GetStartingTime());
						std::string description = event->GetEventDesProper();
						Person person = event->GetPerson();
						std::string firstName = person.GetFirstName();
						std::string lastName = person.GetLastName();
						
						if (firstName.size() < 2)
						{
							firstName = "x";
							lastName = "x";
						}
						
						std::string combinedString = yearNumber + "-" + monthNumber + "-" + dayNumber + "-" + startingTime + "-" + endingTime + "-" + description + "-" + firstName + "-" + lastName;
						myFile << combinedString << std::endl;
					}
				}
			}
		}
	
		myFile.close();
	};

	void LoadData()
	{
		myFile.open("test.txt", std::fstream::in);
		std::string stringToModify;

		while (std::getline(myFile, stringToModify))
		{
			std::vector<std::string> splittedWords = split(stringToModify);

			int nrYear = std::stoi(splittedWords.at(0)) - 2017 ; // to get 0 (2017) or 1(2018) or 2(2019)
			int nrMonth = std::stoi(splittedWords.at(1));
			int nrDay = std::stoi(splittedWords.at(2));
			int nrStartingHour = std::stoi(splittedWords.at(3));
			int nrEndingHoud = std::stoi(splittedWords.at(4));
			std::string description = splittedWords.at(5);
			std::string firstName;
			std::string secondName;
			
			if (splittedWords.at(6) != "x")
			{
				firstName = splittedWords.at(6);
				secondName = splittedWords.at(7);
			}
			Event* eventToAdd = new Event(nrStartingHour,nrEndingHoud,description,Person());
			YearList->at(nrYear)->Months.at(nrMonth)->Days.at(nrDay)->AddEvent(eventToAdd);

		}
		myFile.close();

	}


private:
	std::vector<Year*>* YearList;


	std::fstream myFile;

	std::vector<std::string> split(const std::string& str )
	{
		std::string delimiter = "-";

		std::vector<std::string> tokens;
		size_t prev = 0, pos = 0;
		do
		{
			pos = str.find(delimiter, prev);
			if (pos == std::string::npos) pos = str.length();
				std::string token = str.substr(prev, pos - prev);
			if (!token.empty()) tokens.push_back(token);
				prev = pos + delimiter.length();
		} while (pos < str.length() && prev < str.length());

		return tokens;
	}

	
};

