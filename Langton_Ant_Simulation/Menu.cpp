/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is a menu class that is designed to display a menu for 
                 Project 1.  It can be reused for future projects.
*******************************************************************************/

#include "Menu.hpp"
#include "InputValidation2.hpp"
#include "Ant.hpp"
#include "Board.hpp"

//This file contains the function codes for Menu class
Menu::Menu(string inputName) {

     //set the programName
     programName = inputName;
     
}



//This function displays the header block
void Menu::DisplayHeader() {

     cout << endl << "\t\tWelcome to " << programName << "!" << endl << endl;
     cout << "Please select one of the options below:" << endl;

}



//This function displays the option block
void Menu::DisplayOptions() {

     cout << "\t1. Start Langton's Ant simulation" << endl;
     cout << "\t2. Quit" << endl << endl;

}



//This function displays the menu and asks user if he/she wants to run the program or quit
void Menu::RunProgram() {

     //display the header
     DisplayHeader();

     //variable for storing user's selection
     string userOption = "";
     do {

          //display the option
          DisplayOptions();

          //get user's selection
          cout << ">>>";
          userOption = getValidInput("1|2");

          if (userOption == "1") {

               //Create a new board
               Board newBoard1;

               //start the LangtonAnt simulation
               newBoard1.StartSimulation();
               
          }

     } while (userOption != "2");

}
