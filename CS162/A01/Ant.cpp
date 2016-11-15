/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/07/2016

** Description: Activity 1 - Part of an implementation of Langton's
Ant. This is the implementation file for the Ant class which includes
all the source code for the functions the class contains.

*********************************************************************/

#include "Ant.hpp"
#include "helpers.hpp"

/*********************************************************************

** Description: Ant()

** This is the default consturctor that sets the internal values to
predetermined values. This will ideally never be used but is here to
prevent errors.

*********************************************************************/

Ant::Ant() {
  matrix = createMatrix(10);
  matrixSize = 10;
  xCoord = 0;
  yCoord = 0;
  direction = 0;
  tileColor = matrix[xCoord][yCoord];
  matrix[xCoord][yCoord] = 2;
}

/*********************************************************************

** Description: Ant()

** This is a constructor that takes a pointer to a 2D array, the size
of that 2D array, and the x and y starting coordinates for the ant

*********************************************************************/

Ant::Ant(int** matrixPtr, int matrSize, int startX, int startY) {
  matrix = matrixPtr;
  matrixSize = matrSize;
  xCoord = startX;
  yCoord = startY;
  direction = 0;
  tileColor = matrix[xCoord][yCoord];
  matrix[xCoord][yCoord] = 2;
}

/*********************************************************************

** Description: turn()

** This function makes the ant turn 90 degrees based on the color of
the tile that it is in

*********************************************************************/

void Ant::turn() {
  if (tileColor) {
    direction++;
    if (direction > 3) direction = 0;
  } else {
    direction--;
    if (direction < 0) direction = 3;
  }
}

/*********************************************************************

** Description: flipTile()

** This function flips the color of the current tile from 0 to 1 and
from 1 to 0. In our system, 0 means white and 1 means black.

*********************************************************************/

void Ant::flipTile() {
  matrix[xCoord][yCoord] = !tileColor;
}

/*********************************************************************

** Description: moveForward()

** This function makes the ant move forward one square. If the move is
successful it returns true, and if the move is out of bounds it returns
false. After the move has been completed the function updates the tile
color variable to the color of the new tile, and makes sure the ant is
displayed on the board. 

*********************************************************************/

bool Ant::moveForward() {
  bool moved = true;
  switch (direction) {
    case 0: // up
      if (xCoord == 0) {
        moved = false;
      } else {
        xCoord--;
      }
      break;
    case 1: // right
      if (yCoord == matrixSize - 1) {
        moved = false;
      } else {
        yCoord++;
      }
      break;
    case 2: // down
      if (xCoord == matrixSize - 1) {
        moved = false;
      } else {
        xCoord++;
      }
      break;
    case 3: // left
      if (yCoord == 0) {
        moved = false;
      } else {
        yCoord--;
      }
      break;
  }
  tileColor = matrix[xCoord][yCoord];
  matrix[xCoord][yCoord] = 2;
  return moved;
}
