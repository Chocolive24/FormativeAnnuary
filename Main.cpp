#include "Annuary.h"

#include <iostream>

int main()
{
    bool program = true;

    // Create the annuary.
    Annuary annuary;

    annuary.WelcomeScreen();

    // Display the menu and execute the option chosen by the user.
    annuary.ActivateChosenOption(program, Annuary::DisplayMenuOption());

    while (program)
    {
        // Ask the user to enter a name and a phone number
        // The name is the last parameter because the functions are called from the last to the first.
        annuary.AddNameAndPhoneNumber(annuary.GetPhoneNumber(), annuary.GetName());

        annuary.PrintAnnuary();

        // Display the menu and execute the option chosen by the user.
        annuary.ActivateChosenOption(program, Annuary::DisplayMenuOption());
    } 
}
