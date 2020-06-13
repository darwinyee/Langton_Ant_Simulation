/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the function definitions for input validation functions.
                 I consulted www.cplusplus.com for cctype function isdigit().
*******************************************************************************/

#ifndef DARWIN_YEE_INPUTVALID_HPP
#define DARWIN_YEE_INPUTVALID_HPP

#include <string>
#include <iostream>
#include <limits>
#include <vector>
#include <cctype>

using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;

//function interface for checking specific input matching
bool isSpecificInputValid(string inputToCheck, string specficInput); //specificInput: x|y|z...

//function interface for checking integers only
bool isIntegersOnly(string inputToCheck, bool isNonNegative, int lowBound = std::numeric_limits<int>::min(), int highBound = std::numeric_limits<int>::max());

//function to get valid input from user
string getValidInput(string specificInput); //specificInput: x|y|z...

//function to get valid integers input from user
int getValidInputInteger(int highBound, int lowBound = 0);

#endif
