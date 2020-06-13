/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the header file for input validation functions.  The 
                 input validation methods uses the regular expression to check
                 for specific inputs.  I consulted www.cplusplus.com/reference/regex
                 for the examples of regular expression construction.
*******************************************************************************/

#ifndef DARWIN_YEE_INPUTVALID_HPP
#define DARWIN_YEE_INPUTVALID_HPP

#include <string>
#include <regex>
#include <iostream>
#include <limits>

using std::string;
using std::regex;
using std::cin;
using std::cout;
using std::endl;

//function interface for checking specific input matching
bool isSpecificInputValid(string inputToCheck, string regexRule);

//function interface for checking integers only
bool isIntegersOnly(string inputToCheck, bool isNonNegative, int lowBound=std::numeric_limits<int>::min(), int highBound= std::numeric_limits<int>::max());

//function to get valid input from user
string getValidInput(string regexRule);

//function to get valid integers input from user
int getValidInputInteger(int highBound, int lowBound=0);

#endif