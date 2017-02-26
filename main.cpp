// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include <SFML/Window/Joystick.hpp>
#include <tchar.h>
#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string>
#include <vector>
#include <stdio.h>
#include <chrono>
#include <fstream>

int main()
{
	std::time_t dateNow = std::time(nullptr);
	struct tm time_info;
	localtime_s(&time_info, &dateNow);
	char fileNamet[26];
	strftime(fileNamet, 26, "%Y-%m-%d--%H-%M-%S.csv", &time_info);
	std::string fileName(fileNamet);

	std::ofstream myfile;

	typedef std::chrono::steady_clock clk;
	double timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();

	// Header Inserts
	myfile.open(fileName);

	myfile <<
		"timestamp" << "," <<
		"axis0" << "," <<
		"axis1" << "," << 
		"axis2" << "," << 
		"axis3" << "," << "\n";

	bool connected = sf::Joystick::isConnected(0);

	float axis0 = 0.0;
	float axis1 = 0.0;
	float axis2 = 0.0;
	float axis3 = 0.0;

	while (true) {
		sf::Joystick::update();
		// Is joystick #0 connected?
		connected = sf::Joystick::isConnected(0);
		if (connected) {
			timestamp = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
			
			axis0 = sf::Joystick::getAxisPosition(0, sf::Joystick::X);
			axis1 = sf::Joystick::getAxisPosition(0, sf::Joystick::Z);
			axis2 = sf::Joystick::getAxisPosition(0, sf::Joystick::R);
			axis3 = sf::Joystick::getAxisPosition(0, sf::Joystick::U);

			myfile <<
				std::to_string(timestamp) << "," <<
				axis0 << "," <<
				axis1 << "," <<
				axis2 << "," <<
				axis3 << "," << "\n";

			printf("connected: %d \n", connected);
			printf("timestamp: %.0lf  \n", timestamp);		// time
			printf("x-axis position: %f \n", axis0);		// Steering Wheel
			printf("z-axis rotation: %f \n", axis1);		// Gas
			printf("r-axis position: %f \n", axis2);		// Break
			printf("u-axis position: %f \n", axis3);		// Clutch
													
			system("cls");
		}

		//// How many buttons does joystick #0 support?
		//unsigned int buttons = sf::Joystick::getButtonCount(0);
		//// Does joystick #0 define a X axis?
		//bool hasX = sf::Joystick::hasAxis(0, sf::Joystick::X);
		//// Is button #2 pressed on joystick #0?
		//bool pressed = sf::Joystick::isButtonPressed(0, 2);
		//// What's the current position of the Y axis on joystick #0?
		//float position = sf::Joystick::getAxisPosition(0, sf::Joystick::Y);

		
		//for (int counter_ = 0; counter_ < sf::Joystick::getButtonCount(0); counter_++)
		//{
		//	if (sf::Joystick::isButtonPressed(0,counter_))
		//		printf("rgbButtons: %d \n", counter_);
		//}

	}

	if (myfile.is_open())
		myfile.close();

	return 0;
}

