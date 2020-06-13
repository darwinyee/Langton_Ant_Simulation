/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the function definitions for input validation functions.
                 I consulted www.cplusplus.com for cctype function isdigit().
*******************************************************************************/

#include "InputValidation2.hpp"

//boolean function for checking specific input matching
bool isSpecificInputValid(string inputToCheck, string specificInput) {

     //put all the specific inputs separated by | into vector
     vector <string> inputNeeded;
     unsigned posAfterDelimit = 0;
     for (unsigned n = 0; n < specificInput.length(); n++) {
          if (specificInput.substr(n, 1) == "|") {
               inputNeeded.push_back(specificInput.substr(posAfterDelimit, n - posAfterDelimit));
               posAfterDelimit = n + 1;
          }
     }
          //for the last input needed
     if (posAfterDelimit < specificInput.length())
          inputNeeded.push_back(specificInput.substr(posAfterDelimit, specificInput.length() - posAfterDelimit));

     //loop through the inputNeeded and return true if match found    
     for (unsigned m = 0; m < inputNeeded.size(); m++) {
          if (inputToCheck == inputNeeded[m])
               return true;
     }

     return false;
}

//boolean function for checking integers only
bool isIntegersOnly(string inputToCheck, bool isNonNegative, int lowBound, int highBound) {

     unsigned loopStartPos = 0;   //starting position for inputToCheck to start checking

     //check to see if the input is negative
     if (inputToCheck.substr(0, 1) == "-" && !isNonNegative)
          loopStartPos = 1;
     
     //catch newline input
     if (!std::isdigit(inputToCheck[0]))
          return false;

     //check to see if the input is an valid integer
     for (unsigned n = loopStartPos; n < inputToCheck.length(); n++) {
          if (!std::isdigit(inputToCheck[n]))
               return false;
     }

     //make sure the integer is within bound
     if ((std::stoi(inputToCheck) < lowBound) || (std::stoi(inputToCheck) > highBound))
          return false;

     return true;

}

//function to get valid input from user
string getValidInput(string specificInput) {

     string userInput = "";

     //get user's selection
     std::getline(cin, userInput);

     //input validation
     while (!isSpecificInputValid(userInput, specificInput)) {
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