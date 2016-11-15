/*********************************************************************

** Program Filename: Ant.cpp

** Author: Pedro Torres-Picon

** Date: 11/02/2016

** Description: Lab 5 - Part of a predator/prey simulation.
This is the implementation file for the Ant class, which is derived
from the Critter abstract class. This file includes the source code
for all the functions in the class.

*********************************************************************/

#include "Ant.hpp"

/*********************************************************************

** Description: Ant()

** This is the constructor for the Ant class, which takes a
few arguments, passes them to the Critter base class constructor, and
sets a few more variables specific to this derived class.

*********************************************************************/

Ant::Ant(Critter ***matrPtr, int matrSize, int startX, int startY, int startStep) :
Critter(matrPtr, matrSize, startX, startY, startStep) {

  breedSteps = 3;
  critterType = "Ant";

};

/*********************************************************************

** Description: breed()

** This is the Ant implementation of the breed virtual function in the
Critter base class. The Ant picks a random number to start looking for
a place to place a new Ant around it, creates one and returns true if
there is an open spot, or returns false if there is not.

*********************************************************************/

bool Ant::breed() {

  int counter = rand() % 4;
  bool foundEmpty = false;
  while (!foundEmpty && counter < 7) {

    switch (counter) {

      case 0:
      case 4:
        if (xCoord > 0 && !matrix[xCoord - 1][yCoord]) {
          matrix[xCoord - 1][yCoord] = new Ant(matrix, matrixSize, xCoord - 1, yCoord, stepCounter);
          foundEmpty = true;
        }
        break;

      case 1:
      case 5:
        if (yCoord < matrixSize - 1 && !matrix[xCoord][yCoord + 1]) {
          matrix[xCoord][yCoord + 1] = new Ant(matrix, matrixSize, xCoord, yCoord + 1, stepCounter);
          foundEmpty = true;
        }
        break;

      case 2:
      case 6:
        if (xCoord < matrixSize - 1 && !matrix[xCoord + 1][yCoord]) {
          matrix[xCoord + 1][yCoord] = new Ant(matrix, matrixSize, xCoord + 1, yCoord, stepCounter);
          foundEmpty = true;
        }
        break;

      case 3:
        if (yCoord > 0 && !matrix[xCoord][yCoord - 1]) {
          matrix[xCoord][yCoord - 1] = new Ant(matrix, matrixSize, xCoord, yCoord - 1, stepCounter);
          foundEmpty = true;
        }
        break;

    }
    counter++;
  }
  return foundEmpty;

};

/*********************************************************************

** Description: move()

** This is the Ant implementation of the move virtual function in the
Critter base class. The Ant picks a random number to start looking for
a place to move towards, and moves there if it finds an empty spot. It
returns true if the move was successful and false if it wasn't.

*********************************************************************/

bool Ant::move() {
  int direction = rand() % 4;
  bool moved = false;
  switch (direction) {
    case 0: // up
      if (xCoord > 0 && !matrix[xCoord - 1][yCoord]) {
        matrix[xCoord - 1][yCoord] = this;
        matrix[xCoord][yCoord] = 0;
        xCoord--;
        moved = true;
      }
      break;

    case 1: // right
      if (yCoord < matrixSize - 1 && !matrix[xCoord][yCoord + 1]) {
        matrix[xCoord][yCoord + 1] = this;
        matrix[xCoord][yCoord] = 0;
        yCoord++;
        moved = true;
      }
      break;

    case 2: // down
      if (xCoord < matrixSize - 1 && !matrix[xCoord + 1][yCoord]) {
        matrix[xCoord + 1][yCoord] = this;
        matrix[xCoord][yCoord] = 0;
        xCoord++;
        moved = true;
      }
      break;

    case 3: //left
      if (yCoord > 0 && !matrix[xCoord][yCoord - 1]) {
        matrix[xCoord][yCoord - 1] = this;
        matrix[xCoord][yCoord] = 0;
        yCoord--;
        moved = true;
      }
      break;
  }
  return moved;
};
