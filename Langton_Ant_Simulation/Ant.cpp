/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the function definitions for the Ant class.
*******************************************************************************/

#include "Ant.hpp"
#include <string>
#include <cstdlib>    //for srand and rand
#include <ctime>

using std::string;

//This is the constructor of the Ant class which initializes the location and the orientation of the ant.
Ant::Ant(coordinates inLocation, string inOrientation) {
     
     SetPos(inLocation);

     //default starting orientation is random
     SetOrientation(inOrientation);

}



//This function sets the location of the ant to the value given.
void Ant::SetPos(coordinates newLocation) {

     currentLocation = newLocation;

}



//This function sets the orientation of the ant to the given parameter.
void Ant::SetOrientation(string newOrientation) {

     if(newOrientation != "random")
         currentOrientation = newOrientation;
     else {
          std::srand((unsigned int)std::time(0));
          int index = rand() % 4 + 1;
          switch (index) {
               case 1: 
                    currentOrientation = "e";
                    break;
               case 2:
                    currentOrientation = "s";
                    break;
               case 3:
                    currentOrientation = "w";
                    break;
               case 4:
                    currentOrientation = "n";
          }
     }
}



//This function returns the current position of the ant.
coordinates Ant::GetPos() {

     return currentLocation;

}



//This function returns the current orientation of the ant.
string Ant::GetOrientation() {

     return currentOrientation;

}



/*This function moves the ant based on the color of the cell it is currently on.
  It will calculate the new location that the ant is supposed to move to and
  update the orientation and the location of the ant.  For edge cases, the ant
  will wrap the board around and appear on the other side.*/

void Ant::Move(string ColorOfCell, int boardRows, int boardColumns) {

     //color: white -> " "; black -> "#"

     //determine the next location and the next orientation
     if (currentOrientation == "e") {
          if (ColorOfCell == " ") {
               currentLocation.Row++;
               currentOrientation = "s";
          }
          else {
               currentLocation.Row--;
               currentOrientation = "n";
          }
     }
     else if (currentOrientation == "s") {
          if (ColorOfCell == " ") {
               currentLocation.Column--;
               currentOrientation = "w";
          }
          else {
               currentLocation.Column++;
               currentOrientation = "e";
          }
     }
     else if (currentOrientation == "w") {
          if (ColorOfCell == " ") {
               currentLocation.Row--;
               currentOrientation = "n";
          }
          else {
               currentLocation.Row++;
               currentOrientation = "s";
          }
     }
     else if (currentOrientation == "n") {
          if (ColorOfCell == " ") {
               currentLocation.Column++;
               currentOrientation = "e";
          }
          else {
               currentLocation.Column--;
               currentOrientation = "w";
          }
     }

     //Check and wrap around the board if the new location is out of bound
     if (currentLocation.Row >= boardRows)
          currentLocation.Row = currentLocation.Row - boardRows;
     else if (currentLocation.Row < 0)
          currentLocation.Row = boardRows + currentLocation.Row;

     if (currentLocation.Column >= boardColumns)
          currentLocation.Column = currentLocation.Column - boardColumns;
     else if (currentLocation.Column < 0)
          currentLocation.Column = boardColumns + currentLocation.Column;

}