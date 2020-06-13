/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the main function for the Langton's Ant Simulation.
*******************************************************************************/

#include <iostream>
#include <string>
#include "Menu.hpp"
#include "InputValidation2.hpp"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main() {

     //start the program
     Menu langtonMenu("Langton's Ant Simulation (Extra Credit Version)");
     langtonMenu.RunProgram();

     return 0;

}