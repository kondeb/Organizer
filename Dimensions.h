#pragma once
#include <SFML/Graphics.hpp>

namespace dim {

	sf::Font font;

	std::vector<std::string> MonthNames = { "January", "February", "March", "April", "May", "June", "July", "August" , "September" , "October" , "November" , "December" };

	std::vector<std::string> DayNames = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"  };

		

	/*			RenderWindow											*/

	const sf::Vector2u WindowSize = sf::Vector2u(1280, 720);

	/*			Calendar class											*/

	const sf::Vector2f SizeOfItem_Calendar = sf::Vector2f(160, 160);
	const sf::Vector2f ItemOffset_Calendar = sf::Vector2f(380, 220);
	const sf::Vector2f OffsetBetweenItems_Calendar = sf::Vector2f(200,0);
	const sf::Vector2f TextOffset_Calendar = sf::Vector2f(50, 60);
	const int ThicknessOfBlackOutliner = 100;
	const int TextSize_Calendar = 25;

	/*			Year class												*/

	const sf::Vector2f SizeOfItem_Year = sf::Vector2f(150, 150);
	const sf::Vector2f ItemOffset_Year = sf::Vector2f(340, 135);
	const int OutlineThickness_Year = 5;
	const sf::Vector2f OffsetBetweenItems_Year = SizeOfItem_Year + sf::Vector2f(OutlineThickness_Year, OutlineThickness_Year);
	const sf::Vector2f TextOffset_Year = sf::Vector2f(18, 18);
	const int TextSize_Year = 22;

	/*			Month class												*/

	const sf::Vector2f SizeOfItem_Month = sf::Vector2f(100, 100);
	const sf::Vector2f ItemOffset_Month = sf::Vector2f(300, 100);
	const int OutlineThickness_Month = 3;
	const sf::Vector2f OffestBetweenItems_Month = SizeOfItem_Month + sf::Vector2f(OutlineThickness_Month, OutlineThickness_Month);
	const sf::Vector2f TextOffset_Month = sf::Vector2f(15, 15);
	const sf::Vector2f DayNamesOffset = sf::Vector2f(300, 60);
	const int TextSize_Month = 17;

		/*			Week view											*/

		const sf::Vector2f SizeOfItem_Week = sf::Vector2f(100, 500);
		const sf::Vector2f ItemOffset_Week = sf::Vector2f(300, 100);
		const int OutlineThickness_Week = 3;
		const sf::Vector2f OffestBetweenItems_Week = SizeOfItem_Week + sf::Vector2f(OutlineThickness_Week, OutlineThickness_Week);
		const sf::Vector2f TextOffset_Week = sf::Vector2f(15, 15);
		const sf::Vector2f DayNamesOffset_Week = sf::Vector2f(300, 60);
		const int TextSize_Week = 17;

		
		const sf::Vector2f SizeOfEventTextBox_Week = sf::Vector2f(90, 80);
		const sf::Vector2f EventTextOffset_Week = sf::Vector2f(5, 5);
		const sf::Vector2f TextNameEventOffset_Week = sf::Vector2f(0, 40);
		const int EventTextSize_Week = 14;
		

	/*			Day class												*/

	const sf::Vector2f SizeOfItem_Day = sf::Vector2f(800, 40);
	const sf::Vector2f NoEventsTextPosition_Day = sf::Vector2f(500, 200);
	const sf::Vector2f ItemOffset_Day = sf::Vector2f(240, 150);
	const sf::Vector2f OffsetBetweenItems_Day = sf::Vector2f(0, 45);
	const sf::Vector2f TextOffset_Day = sf::Vector2f(5, 5);
	const sf::Vector2f TextNameEventOffset_Day = sf::Vector2f(200, 0);
	const int NoEventTextSize_Day = 40;
	const int EventTextSize_Day = 25;

	/*			Add Event button										*/
	
	const sf::Vector2f SizeOfButton = sf::Vector2f(150, 40);
	const sf::Vector2f ButtonOffset = sf::Vector2f(1080, 70);
	const int OutlineThickness_Button = 3;
	const sf::Vector2f TextOffset_Button = sf::Vector2f(10,3);
	const int TextSize_Button = 15;

	/*			Event Helper											*/

		/*			CheckBoxes										*/
		const sf::Vector2f SizeOfCheckBox_Helper = sf::Vector2f(20, 20);
		const sf::Vector2f CheckBoxOffset_Helper = sf::Vector2f(200, 100);
		const sf::Vector2f OffsetBetweekCheckBoxes_Helper = sf::Vector2f(200, 0);
		const int OutlineThickness_Helper = 5;
		const sf::Vector2f CheckBoxTextOffset_Helper = sf::Vector2f(30, 0);
		const int CheckBoxTextSize_Helper = 17;

		/*			Description Text Box							*/
		const sf::Vector2f SizeOfDescriptionBox_Helper = sf::Vector2f(600, 30);
		const sf::Vector2f DescriptionBoxOffset_Helper = sf::Vector2f(200, 200);
		const int OutlineThicknessDescriptionBox_Helper = 5;
		
		const int TextSizeDescriptionBox_Helper = 26;
		const sf::Vector2f TextDescriptionBoxOffset_Helper = sf::Vector2f(2, -2);

		/*			DD/MM/YYYY										*/

		const sf::Vector2f SizeOfDDMMYYYYBox_Helper = sf::Vector2f(50, 30);
		const sf::Vector2f DDMMYYYYBoxOffset_Helper = sf::Vector2f(200, 300);
		const sf::Vector2f OffsetBetweenDDMMYYYYBoxes_Helper = sf::Vector2f(SizeOfDDMMYYYYBox_Helper.x + 20, 0);
		const int OutlineThicknessDDMMYYYYBox_Helper = 5;

		const int TextSizeDDMMYYYY_Helper = 26;
		const sf::Vector2f TextDDMMYYYYBoxOffset_Helper = sf::Vector2f(2, -2);

		/*			HH MM											*/

		const sf::Vector2f SizeOfHHMMBox_Helper = sf::Vector2f(50, 30);
		const sf::Vector2f HHMMBoxOffset_Helper = sf::Vector2f(500, 300);
		const sf::Vector2f OffsetBetweenHHMMBoxes_Helper = sf::Vector2f(SizeOfDDMMYYYYBox_Helper.x + 20, 0);
		const int OutlineThicknessHHMMBox_Helper = 5;

		const int TextSizeHHMM_Helper = 26;
		const sf::Vector2f TextHHMMBoxOffset_Helper = sf::Vector2f(2, -2);


		const sf::Vector2f EndingHHMMBoxOffset_Helper = sf::Vector2f(700, 300);


		/*			Periodic & LongTerm								*/

		const sf::Vector2f InfoTextOffset_Helper = sf::Vector2f(200, 350);
		const sf::Vector2f SizeOfPeriodicBox_Helper = sf::Vector2f(50, 30);
		const sf::Vector2f PeriodicBoxOffset_Helper = sf::Vector2f(200, 400);
		const sf::Vector2f OffsetBetweenPeriodicBoxes_Helper = sf::Vector2f(SizeOfDDMMYYYYBox_Helper.x + 20, 0);
		const int OutlineThicknessPeriodicBox_Helper = 5;

		const int TextSizePeriodic_Helper = 26;
		const sf::Vector2f TextPeriodicBoxOffset_Helper = sf::Vector2f(2, -2);

		/*			Person											*/

		const sf::Vector2f InfoPersonTextOffset_Helper = sf::Vector2f(200, 450);
		const sf::Vector2f SizeOfPersonBox_Helper = sf::Vector2f(200, 30);
		const sf::Vector2f PersonBoxOffset_Helper = sf::Vector2f(200, 500);
		const sf::Vector2f OffsetBetweenPersonBoxes_Helper = sf::Vector2f(SizeOfPersonBox_Helper.x + 20, 0);
		const int OutlineThicknessPersonBox_Helper = 5;

		const int TextSizePerson_Helper = 26;
		const sf::Vector2f TextPersonBoxOffset_Helper = sf::Vector2f(2, -2);


}