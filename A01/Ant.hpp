/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/07/2016

** Description: Activity 1 - Part of an implementation of Langton's
Ant. This is the interface file for the Ant class, which includes the
class, variable and function declarations.

*********************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

// Defines the interface of the Ant class
class Ant
{
  private:
    int direction; // direction the ant is currently facing - 0 is up, and numbers increase clockwise
    int tileColor; // color of the tile where the ant is currently standing - 0 is white, 1 is black
    int xCoord; // current x coord for the ant
    int yCoord; // current y coord for the ant
    int** matrix; // internal variable to hold the matrix that the ant will use to move around in
    int matrixSize; // internal variable to hold the size of matrix

  public:
    Ant();
    Ant(int** matrixPtr, int matrSize, int startX, int startY);
    void turn();
    void flipTile();
    bool moveForward();
};
#endif
