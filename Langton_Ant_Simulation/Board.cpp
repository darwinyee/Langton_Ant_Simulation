/*******************************************************************************
** Author:       Darwin Yee
** Date:         04-02-2019
** Description:  This is the function definitions for the Board class.
*******************************************************************************/

#include <iostream>
#include <string>
#include <cstdlib>    //for srand and rand
#include <ctime>
#include "Ant.hpp"
#include "Board.hpp"
#include "InputValidation2.hpp"

using std::string;
using std::cin;
using std::cout;
using std::endl;

//Constructor that set up the board and the ant by asking user for the size of the board,
//the ant's starting location and the number of steps to run the simulation
Board::Board() {

     //variables for storing user inputs
     string antPosRandom = "N";
     coordinates antStartLoc;

     //variables for maximum dimension, maximum steps
     int maxBoardRows = 50, maxBoardCols = 80, maxSteps = 10000;

     //ask for the size of the board and how many simulation he/she wants to run
     cout << endl << "Setting up the board dimension and the number of simulations...." << endl << endl;
     cout << "Please enter the number of rows for the board " << "(1 <= Rows <= " << maxBoardRows << "):";
     boardRows = getValidInputInteger(maxBoardRows, 1);
     cout << "Please enter the number of columns for the board " << "(1 <= columns <= " << maxBoardCols << "):";
     boardColumns = getValidInputInteger(maxBoardCols, 1);
     cout << "Please enter the number of simulations you want to perform " << "(1 <= steps <=" << maxSteps << "):";
     simulationSteps = getValidInputInteger(maxSteps, 1);

     //ask for the starting position of the ant
     cout << endl << "Retrieving the ant's starting position...." << endl << endl;
     cout << "Do you want a random starting position for the ant? (Y or N) ";
     antPosRandom = getValidInput("Y|y|N|n");
     if (antPosRandom == "Y" || antPosRandom == "y") {
          antStartLoc.Row = RandomInteger(boardRows - 1, 0);
          antStartLoc.Column = RandomInteger(boardColumns - 1, 0);
     }
     else {
          cout << "Please enter the row where you want the ant to be placed " << "(0 <= Row <= " << boardRows - 1 << "):";
          antStartLoc.Row = getValidInputInteger(boardRows - 1);
          cout << "Please enter the column where you want the ant to be placed " << "(0 <= Column <= " << boardColumns - 1 << "):";
          antStartLoc.Column = getValidInputInteger(boardColumns - 1);
     }

     //Create the board
     CreateBoard();

     //Add an ant to the board
     newAnt1 = new Ant(antStartLoc);

}

//Overload Constructor to dynamically allocated 2D Array
Board::Board(int inRows, int inColumns, coordinates AntStartLocation, int steps) {

     //Create the 2D Board
     boardRows = inRows; boardColumns = inColumns;
     CreateBoard();

     //Set the number of steps for simulation
     simulationSteps = steps;

     //Add an ant to the board
     newAnt1 = new Ant(AntStartLocation);
}

//Function to dynamically create the board for the ant
void Board::CreateBoard() {

     //Create the 2D Board
     newBoard = new string*[boardRows];
     for (int n = 0; n < boardRows; n++)
          newBoard[n] = new string[boardColumns];

     //initialize the board to all white color
     for (int nRow = 0; nRow < boardRows; nRow++) {
          for (int nCol = 0; nCol < boardColumns; nCol++) {
               newBoard[nRow][nCol] = " ";
          }
     }

}

//Function to change color of a specific cell
void Board::ChangeColor(coordinates targetCell) {
     
     if (newBoard[targetCell.Row][targetCell.Column] == " ")
          newBoard[targetCell.Row][targetCell.Column] = "#";
     else if (newBoard[targetCell.Row][targetCell.Column] == "#")
          newBoard[targetCell.Row][targetCell.Column] = " ";

}

//Function to perform the simulation
void Board::StartSimulation() {

     //print the board before the simulation starts
     PrintBoard(0);

     //move the ant and display the board in a for loop for the number of steps defined
     for (int n = 1; n <= simulationSteps; n++) {

          //record the old ant location
          coordinates oldAntLoc = newAnt1->GetPos();
          
          //move the ant
          newAnt1->Move(newBoard[newAnt1->GetPos().Row][newAnt1->GetPos().Column],boardRows,boardColumns);
 
          //change the color of the previous ant location
          ChangeColor(oldAntLoc);

          //print the board on the screen
          PrintBoard(n);
     }

     //Tell the user simulation is done
     cout << endl << "Simulation is done successfully! Do you want to simulate again?" << endl << endl;

}

//Function to print the board
void Board::PrintBoard(int currentStep) {

     //Clear the screen
     //system("CLS");

     //Display the spec of the simulations
     cout << endl << string(90,'*') << endl << endl;
     cout << "Board Size: " << boardRows << " x " << boardColumns << endl;
     cout << "Ant's Current Position: " << "(" << newAnt1->GetPos().Row << ", " << newAnt1->GetPos().Column << ")" << endl;
     cout << "Ant's Current Orientation: " << newAnt1->GetOrientation() << endl;
     cout << "Simulation " << currentStep << " of " << simulationSteps << ":" << endl;

     //temporary store the color of the ant location
     coordinates AntLoc = newAnt1->GetPos();
     string AntLocColor = newBoard[AntLoc.Row][AntLoc.Column];

     //Change the Ant location on the board from color to Ant Symbol
     newBoard[AntLoc.Row][AntLoc.Column] = "*";

     //Print the board on screen
     cout << string(boardColumns + 2, '-') << endl;
     for (int nRow = 0; nRow < boardRows; nRow++) {
          cout << "|";
          for (int nCol = 0; nCol < boardColumns; nCol++) {
               cout << newBoard[nRow][nCol];
          }
          cout << "|" << endl;
     }
     cout << string(boardColumns + 2, '-') << endl;

     //Change the Ant location back to color
     newBoard[AntLoc.Row][AntLoc.Column] = AntLocColor;

}

//Function to generate a random number within a specific range
int Board::RandomInteger(int upperbound, int lowerbound) {

     std::srand((unsigned int)std::time(0));
     return rand() % (upperbound-lowerbound + 1) + lowerbound;

}

//destructor to remove the dynamically allocated 2D Array and the ant
Board::~Board() {

     //delete the 2D array
     for (int i = 0; i < boardRows; i++) {
          delete[] newBoard[i];
     }
     delete[] newBoard;

     //delete the ant
     delete newAnt1;

}