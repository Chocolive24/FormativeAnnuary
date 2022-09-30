#include "Annuary.h"
#include "conio.h" // For the _getch() function.

#include <iostream>

// Ignore the input in a line. 
void Annuary::IgnoreLigne()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// Ask an input to the user and get it.
std::string Annuary::GetCin()
{
    std::cout << "-> ";
    std::string userCin;
    std::getline(std::cin, userCin);

    return userCin;
}

void Annuary::WelcomeScreen()
{
    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
    std::cout << "+++ Welcome to the Annuary+++" << std::endl;
    std::cout << "+++++++++++++++++++++++++++++" << std::endl;
}

std::string Annuary::DisplayMenuOption()
{
    // Show the user the possible options of the program.
    std::cout << std::endl;
    std::cout << "====================Menu========================" << std::endl;
    std::cout << "[1] to add names and phone numbers.             " << std::endl;
    std::cout << "[2] to find a phone number by using a name.     " << std::endl;
    std::cout << "[3] (or any other key) to quite the program.    " << std::endl;
    std::cout << "================================================" << std::endl;

    // Get the option chosen by the user.
    std::string userAnswer = GetCin();
    system("cls");

    return userAnswer;
}

std::string Annuary::GetName()
{
	// Ask the user to tap a last name and a first name.
    std::cout << "Tap someone's last name and first name." << std::endl;
    std::cout << "-> ";

    std::string name;

    do
    {
        // Get the key pressed by the user in a variable.
        char key = _getch();

        // Check if the key pressed is a lowercase or an uppercase letter or a space (the numbers are ASCII ones).
        // That way the user can't type any number or other invalid character for a name.
        if (key >= 65 && key <= 90 || key >=97 && key <= 122 || key == 32)
        {
            // Add the key value in the name variable
            name += key;
            std::cout << key;
        }

        // If the key pressed is "delete".
        if (key == 8)
        {
            // If the name is not empty.
            if (!name.empty())
            {
                // Delete the last character and put the cursor back from 1 character in the console.
                name.pop_back();
                std::cout << "\b \b";
            }
        }

        // If the key pressed is "enter".
        if (key == 13)
        {
            if (name.empty())
            {
                // The the name don't contain any character, so ask the user to enter at least one character.
                std::cout << std::endl << "No name entered. Please enter a valid one" << std::endl;
                std::cout << "-> ";
            }

            else
            {
                break;
            }
        }

    } while (true);

    return name;
}

std::string Annuary::GetPhoneNumber()
{
	// Ask the user to tap the phone number of the corresponding name.
	std::cout << std::endl << "Now enter the phone number of this person." << std::endl;
    std::cout << "-> ";

    std::string phoneNumber;

    do
    {
        // Get the key pressed by the user in a variable.
        char key = _getch();

        // Check if the key pressed is a number or the "+" character or a space (the numbers are ASCII ones).
        // That way the user can't type any letter or other invalid character for a phone number.
        if (key >= 48 && key <= 57 || key == 43 || key == 32)
        {
            // Add the key value in the phone number variable.
            phoneNumber += key;
            std::cout << key;
        }

        // If the key pressed is "delete".
        if (key == 8)
        {
            // If the phone number is not empty.
	        if (!phoneNumber.empty())
	        {
                // Delete the last character and put the cursor back from 1 character in the console.
                phoneNumber.pop_back();
                std::cout << "\b \b";
	        }
        }

        // If the key pressed is "enter".
        if (key == 13)
        {
	        if (phoneNumber.empty())
	        {
                // The phone number don't contain any character, so ask the user to enter at least one character.
                std::cout << std::endl << "No phone number entered. Please enter a valid one" << std::endl;
                std::cout << "-> ";
	        }

            else
            {
                break;
            }
        }

    } while (true);

	system("cls");

	return phoneNumber;
}

void Annuary::AddNameAndPhoneNumber(std::string phoneNumber, std::string name)
{
    std::string userAnswer;

    // For each elements in the annuary.
    for (auto it = _annuary.begin(); it != _annuary.end(); it++)
    {
        // If someone's name is already in the annaury, ask the user if he want to replace it.
        if (it->first == name)
        {
            std::cout << "This person already exist. Would you like to replace it with the new information ?" << std::endl;
            std::cout << "====================================================" << std::endl;
            std::cout << "[1] to replace it with the new information.         " << std::endl;
            std::cout << "[2] (or any other key) to keep the old information. " << std::endl;
            std::cout << "====================================================" << std::endl;
        	userAnswer = GetCin();
            system("cls");
        }
    }

    // If the user wants to replace the name, delete the previous one and add the new one.
    if (userAnswer == "1")
    {
        auto it = _annuary.find(name);
        _annuary.erase(it);
    }

    // Add the full name and the phone number to the annuary.
    std::pair<std::string, std::string> p(name, phoneNumber);
    _annuary.insert(p);
}

void Annuary::PrintAnnuary()
{
    std::cout << "Annuary :" << std::endl;

	// Print the annuary (alphabetical order).
	for (auto it = _annuary.begin(); it != _annuary.end(); it++)
	{
		std::cout << it->first << ", " << it->second << '\n'; // First = key, second = value.
	}
}

// Control the option 2 of the menu which is the possibility to find a phone number with the name of a person.
bool Annuary::OptionTwo(bool& program, std::map<std::string, std::string>& annuary)
{
    do
    {
        // Ask the name of the person. 
        std::cout << "Tap a full name to find his/her phone number." << std::endl;
        std::string nameToFindANumber = GetCin();

        // Show his/her phone number.
        std::cout << "-> " << nameToFindANumber << "'s phone number : " << annuary[nameToFindANumber] << std::endl;

        // Show the different menu options and get the choice of the user.
        std::string userAnswer = DisplayMenuOption();

        // If option 1, the user can continue to add names and phone numbers.
        if (userAnswer == "1")
        {
            program = true;
            break;
        }

        // If not option 1 or 2, quite the program.
        if (userAnswer != "1" && userAnswer != "2")
        {
            program = false;
            std::cout << "See you soon !" << std::endl;
            break;
        }

    } while (true);

    return program;
}

// Activate the menu option chosen by the user.
bool Annuary::ActivateChosenOption(bool& program, std::string chosenOption)
{
    // If option 1, the user can continue to add names and phone numbers.
    if (chosenOption == "1")
    {
        program = true;
    }

    // If option 2, activate the OptionTwo function which consist to find a phone number with someone's name.
    else if (chosenOption == "2")
    {
        OptionTwo(program, _annuary);
    }

    // If option 3, quite the program.
    else
    {
        program = false;
        std::cout << "See you soon !" << std::endl;
    }

    return program;
}