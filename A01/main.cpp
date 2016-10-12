/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/07/2016

** Description: Activity 1 - Part of an implementation of Langton's
Ant. This is the main file for the program, which uses the Ant class
and helper functionsn to run the actual program the user sees.

*********************************************************************/

#include "Ant.hpp"
#include "helpers.hpp"
#include <iostream>

int main() {

  int boardSize = getMatrixSize(); // get the matrix size from the user
  int numMoves = getNumMoves(); // get the number of moves from the user
  int xCoord, yCoord; // values to hold x and y coordinates of the starting position
  getStartCoords(&xCoord, &yCoord, boardSize); // get starting coordinates
  int** boardMatrix = createMatrix(boardSize); // create the matrix that will serve as the board
  Ant grant(boardMatrix, boardSize, xCoord, yCoord); // initialize Grant the Ant
  bool grantFell = false; // flag to store whether Grant fell off the board
  int i = 0; // counter for the while loop

  while (i < numMoves && !grantFell) { // while we're under the max number of moves, and Grant has not fallen off...
    i++; // increase the counter
    clearScreen(); // clear the screen so we can see the new state of the board
    std::cout << "MOVES: " << i << std::endl; // print the number of moves the ant has made at the top of the screen
    displayBoard(boardMatrix,boardSize); // display the board on the screen
    grant.turn(); // turn the ant
    grant.flipTile(); // flip the current tile
    if (!grant.moveForward()) { // move forward, but check if succesful
      grantFell = !grantFell; // if not successful, switch the flag
      std::cout << "OH NO! THE ANT FELL OFF THE BOARD AFTER " << i << " MOVES!" << std::endl; // and tell the user what happened
      std::cout << "Tip: try specifying a larger board next time." << std::endl; // and tell the user what happened
    }
  }
  deallocate(boardMatrix, boardSize); // this deallocates the memory for the board matrix
  
  return 0;
}
