/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the header file for the Menu class, which is designed 
                 to display a menu asking for user inputs before starting the 
                 program.
*******************************************************************************/


#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
using std::string;
using std::cin;
using std::cout;
using std::endl;

//Define the interface of the Menu class

class Menu {

     private:
          string programName;
          void DisplayHeader();
          void DisplayOptions();

     public:

          //Create a class object for a specific project
          void RunProgram();

          //Display the menu with a user input header
          Menu(string);

};

#endif
