/*********************************************************************

** Program Filename: Doodlebug.cpp

** Author: Pedro Torres-Picon

** Date: 11/02/2016

** Description: Lab 5 - Part of a predator/prey simulation.
This is the implementation file for the Doodlebug class, which is derived
from the Critter abstract class. This file includes the source code
for all the functions in the class.

*********************************************************************/

#include "Doodlebug.hpp"

/*********************************************************************

** Description: Doodlebug()

** This is the constructor for the Doodlebug class, which takes a
few arguments, passes them to the Critter base class constructor, and
sets a few more variables specific to this derived class.

*********************************************************************/

Doodlebug::Doodlebug(Critter ***matrPtr, int matrSize, int startX, int startY, int startStep) :
Critter(matrPtr, matrSize, startX, startY, startStep) {
  breedSteps = 8;
  critterType = "Doodlebug";
  stepsWithoutEating = 0;
};

/*********************************************************************

** Description: breed()

** This is the Doodlebug implementation of the breed virtual function in the
Critter base class. The Doodlebug picks a random number to start looking for
a place to place a new Doodlebug around it, creates one and returns true if
there is an open spot, or returns false if there is not.

*********************************************************************/

bool Doodlebug::breed() {
  int counter = rand() % 4;
  bool foundEmpty = false;

  while (!foundEmpty && counter < 7) {

    switch (counter) {

      case 0:
      case 4:

        if (xCoord > 0 && !matrix[xCoord - 1][yCoord]) {
          matrix[xCoord - 1][yCoord] = new Doodlebug(matrix, matrixSize, xCoord - 1, yCoord, stepCounter);
          foundEmpty = true;
        }
        break;

      case 1:
      case 5:

        if (yCoord < matrixSize - 1 && !matrix[xCoord][yCoord + 1]) {
          matrix[xCoord][yCoord + 1] = new Doodlebug(matrix, matrixSize, xCoord, yCoord + 1, stepCounter);
          foundEmpty = true;
        }
        break;

      case 2:
      case 6:

        if (xCoord < matrixSize - 1 && !matrix[xCoord + 1][yCoord]) {
          matrix[xCoord + 1][yCoord] = new Doodlebug(matrix, matrixSize, xCoord + 1, yCoord, stepCounter);
          foundEmpty = true;
        }
        break;

      case 3:

        if (yCoord > 0 && !matrix[xCoord][yCoord - 1]) {
          matrix[xCoord][yCoord - 1] = new Doodlebug(matrix, matrixSize, xCoord, yCoord - 1, stepCounter);
          foundEmpty = true;
        }
        break;

    }
    counter++;
  }
  return foundEmpty;
};

/*********************************************************************

** Description: eat()

** This function tries to find an Ant in a space adjacent to this
Doodlebug, and if it finds one it deletes it and takes its place on
the grid. If the eat is successful it returns true, and returns false
otherwise.

*********************************************************************/

bool Doodlebug::eat() {
  int counter = rand() % 4;
  bool ateAnt = false;
  while (!ateAnt && counter < 7) {
    switch (counter) {
      case 0:
      case 4:
        if (xCoord > 0 && matrix[xCoord - 1][yCoord] && matrix[xCoord - 1][yCoord]->type() == "Ant") {
          delete matrix[xCoord - 1][yCoord];
          matrix[xCoord - 1][yCoord] = this;
          matrix[xCoord][yCoord] = 0;
          xCoord--;
          ateAnt = true;
        }
        break;

      case 1:
      case 5:
        if (yCoord < matrixSize - 1 && matrix[xCoord][yCoord + 1] && matrix[xCoord][yCoord + 1]->type() == "Ant") {
          delete matrix[xCoord][yCoord + 1];
          matrix[xCoord][yCoord + 1] = this;
          matrix[xCoord][yCoord] = 0;
          yCoord++;
          ateAnt = true;
        }
        break;

      case 2:
      case 6:
        if (xCoord < matrixSize - 1 && matrix[xCoord + 1][yCoord] && matrix[xCoord + 1][yCoord]->type() == "Ant") {
          delete matrix[xCoord + 1][yCoord];
          matrix[xCoord + 1][yCoord] = this;
          matrix[xCoord][yCoord] = 0;
          xCoord++;
          ateAnt = true;
        }
        break;

      case 3:
        if (yCoord > 0 && matrix[xCoord][yCoord - 1] && matrix[xCoord][yCoord - 1]->type() == "Ant") {
          delete matrix[xCoord][yCoord - 1];
          matrix[xCoord][yCoord - 1] = this;
          matrix[xCoord][yCoord] = 0;
          yCoord--;
          ateAnt = true;
        }
        break;

    }
    counter++;
  }
  if (ateAnt) {
    stepsWithoutEating = 0;
  }
  return ateAnt;
};

/*********************************************************************

** Description: move()

** This is the Doodlebug implementation of the move virtual function
in the Critter base class. The Doodlebug version is a bit more complicated
than the Ant version. Before moving normally, the Doodlebug tries to find
an Ant around itself, and if it finds one it deletes it and takes its
place on the board.

If it does not find one then it picks a random number
to start looking for a place to move towards, and moves there if it finds
an empty spot. It returns true if the move was successful and false if it wasn't.

*********************************************************************/

bool Doodlebug::move() {
  bool moved = true;
  if (!eat()) {
    stepsWithoutEating++;
    if (stepsWithoutEating == 3) {
      moved = false;
    } else {
      int direction = rand() % 4;
      switch (direction) {
        case 0:
          if (xCoord != 0 && !matrix[xCoord - 1][yCoord]) {
            matrix[xCoord - 1][yCoord] = this;
            matrix[xCoord][yCoord] = 0;
            xCoord--;
          }
          break;

        case 1:
          if (yCoord != matrixSize - 1 && !matrix[xCoord][yCoord + 1]) {
            matrix[xCoord][yCoord + 1] = this;
            matrix[xCoord][yCoord] = 0;
            yCoord++;
          }
          break;

        case 2:
          if (xCoord != matrixSize - 1 && !matrix[xCoord + 1][yCoord]) {
            matrix[xCoord + 1][yCoord] = this;
            matrix[xCoord][yCoord] = 0;
            xCoord++;
          }
          break;

        case 3:
          if (yCoord != 0 && !matrix[xCoord][yCoord - 1]) {
            matrix[xCoord][yCoord - 1] = this;
            matrix[xCoord][yCoord] = 0;
            yCoord--;
          }
          break;

      }
    }
  }
  return moved;
};
