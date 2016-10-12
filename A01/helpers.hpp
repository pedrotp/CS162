/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/07/2016

** Description: Activity 1 - Part of an implementation of Langton's
Ant. This is the "helpers" interface file that includes helper function
declarations.

*********************************************************************/

#ifndef HELPERS_HPP
#define HELPERS_HPP

  int getMatrixSize(); // used to get the size of the matrix/board from the user
  int getNumMoves(); // used to get the max number of moves from the user
  void getStartCoords(int* xCoord,int* yCoord, int matrixSize); // used to set the starting coordinates
  int** createMatrix(int matrixSize); // creates a AxA matrix where A is matrixSize
  void clearScreen(); // clears the screen by printing whitespace and other tricks
  void displayBoard(int** board, int size); // displays the current state of the board to the screen
  int getInt(int minSize, int maxSize = 100000000); // registers and validates input for a number between minSize and maxSize, both inclusive
  char getYesNo(); // registers and validates yes/no input
  void genMenu(int minValue, int maxValue); // generic menu function
  void deallocate(int** board, int size); // deallocates memory for a matrix created by createMatrix

#endif
