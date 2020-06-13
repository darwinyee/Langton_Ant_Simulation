/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the function definitions for input validation functions.
                 The input validation methods uses the regular expression to check
                 for specific inputs.  I consulted www.cplusplus.com/reference/regex
                 for the examples of regular expression construction.
*******************************************************************************/

#include "InputValidation.hpp"

//boolean function for checking specific input matching
bool isSpecificInputValid(string inputToCheck, string regexRule) {

     //define regex matching string
     regex rule(regexRule);

     //check to see if the input matches the rule
     if (std::regex_match(inputToCheck, rule))
          return true;

     return false;
}

//boolean function for checking integers only
bool isIntegersOnly(string inputToCheck, bool isNonNegative, int lowBound, int highBound) {

     //define regex matching string
     string regexRule = "^-?\\d+$";
     if (isNonNegative)
          regexRule = "^\\d+$";
     regex rule(regexRule);
     
     //check to see if the input matches the rule
     if (std::regex_match(inputToCheck, rule))

          //check to see if the integer is within specific bound
          if (std::stoi(inputToCheck) <= highBound && std::stoi(inputToCheck) >= lowBound)
               return true;

     return false;

}

//function to get valid input from user
string getValidInput(string regexRule) {

     string userInput = "";

     //get user's selection
     std::getline(cin, userInput);

     //input validation
     while (!isSpecificInputValid(userInput, regexRule)) {
          cout << "Invalid Entry! Please enter again! ";
          std::getline(cin, userInput);
     }

     return userInput;
}

//function to get valid integers input from user
int getValidInputInteger(int highBound, int lowBound) {

     string userInput = "";

     //get user's input value
     std::getline(cin, userInput);

     //input validation
     bool IsNotNegative = false;
     if (lowBound >= 0)
          IsNotNegative = true;

     while (!isIntegersOnly(userInput, IsNotNegative, lowBound, highBound)) {
          cout << "Invalid integer! Please enter again! ";
          std::getline(cin, userInput);
     }

     return std::stoi(userInput);
}