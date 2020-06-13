/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the header file for the Board class, which has three int
                 fields for the rows and columns of the board and the number of
                 simulations needed.  It has two pointer variables for dynamically
                 allocating memory for a board and an ant.  It has a default 
                 constructor which asks for user inputs for the size of the 
                 board, the starting position of the ant and the number of 
                 simulation steps needed.  It has an overloaded constructor which
                 is using for debugging purpose.  It has a Createboard function
                 which dynamically allocates a 2D array of board, a ChangeColor 
                 function to filp the color of the cell on the board, a function 
                 to generate random integer, a function to print the board, and
                 a function to start the simulation.  It also has a destructor
                 to free the dynamically allocated memory when the object goes
                 out of scope.
*******************************************************************************/


#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"

using std::cin;
using std::cout;
using std::endl;

//Define the interface of the Board class

class Board {

     private:
          int simulationSteps, boardRows, boardColumns;
          string **newBoard = nullptr;
          Ant *newAnt1 = nullptr;

          //Function to generate a random number within a specific range
          int RandomInteger(int upperbound, int lowerbound);

     public:

          //Constructor that set up the board and the ant by asking user for the size of the board,
          //the ant's starting location and the number of steps to run the simulation
          Board();

          //Overload Constructor to set up the board with the size of the board,
          //the ant's starting location and the number of steps to run the simulation.
          //This is mainly for testing purpose.
          Board(int inRows, int inColumns, coordinates AntStartLocation, int steps);

          //Function to dynamically create the board for the ant
          void CreateBoard();

          //Function to change color of a specific cell
          void ChangeColor(coordinates targetCell);

          //Function to perform the simulation
          void StartSimulation();

          //Function to print the board
          void PrintBoard(int currentStep);

          //destructor to remove the dynamically allocated 2D Array
          ~Board();

};

#endif
