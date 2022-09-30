#pragma once

#include <map>
#include <string>

class Annuary
{
private:

	std::map<std::string, std::string> _annuary;

public:

	// Useful functions.
	static void IgnoreLigne();
	static std::string GetCin();

	// Functions that display screens / menus.
	void WelcomeScreen();
	static std::string DisplayMenuOption();

	// Functions that add elements in the annuary and print it.
	std::string GetName();
	std::string GetPhoneNumber();
	void AddNameAndPhoneNumber(std::string phoneNumber, std::string name);
	void PrintAnnuary();

	// Functions that control and execute the menu options.
	static bool OptionTwo(bool& program, std::map<std::string, std::string>& annuary);
	bool ActivateChosenOption(bool& program, std::string chosenOption);
};


