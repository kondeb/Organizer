#pragma once
#include <iostream>
class Person {

	std::string FirstName, LastName;

public:
	Person() {};

	Person(std::string firstname,std::string lastname)
	{
		this->FirstName = firstname;
		this->LastName = lastname;
	}

	~Person() {};

	bool operator == (const Person& other) const
	{
		if ((this->FirstName == other.FirstName) && (this->LastName == other.LastName))
			return true;

		return false;
	}

	std::string GetFirstName()
	{
		return FirstName;
	}
	std::string GetLastName()
	{
		return LastName;
	}
};