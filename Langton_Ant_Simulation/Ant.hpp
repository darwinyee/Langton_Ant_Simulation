/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the header file for the Ant class, which has two fields
                 for the location and the orientation of the ant.  It has get/set
                 methods for the two fields and a public function Move which 
                 moves the ant according to the color given as parameter.
*******************************************************************************/


#ifndef ANT_HPP
#define ANT_HPP

#include <string>
using std::string;

//Define the interface of the Ant class

//structure for the board's coordinate
struct coordinates {
     int Row;
     int Column;
};

class Ant {

     private:
          string currentOrientation;
          coordinates currentLocation;

     public:

          //constructor to set up the ant
          Ant(coordinates inLocation, string inOrientation = "random");         

          //set the position of the ant
          void SetPos(coordinates newLocation);

          //set the orientation of the ant
          void SetOrientation(string newOrientation);

          //return the position of the ant as coordinates structure
          coordinates GetPos();

          //return the orientation of the ant (e = east, s = south, n = north, w = west)
          string GetOrientation();

          //move the ant according to the color of the cell and wrap the ant around 
          //the board based on the given maximun rows and colomns of the board
          void Move(string ColorOfCell, int boardRows, int boardColumns);

};

#endif
