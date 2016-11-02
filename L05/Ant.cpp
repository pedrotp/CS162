#include "Ant.hpp"

Ant::Ant(Critter ***matrPtr, int matrSize, int startX, int startY) :
Critter(matrPtr, matrSize, startX, startY) {
  breedSteps = 3;
  critterType = "Ant";
};

bool Ant::breed() {
  int counter = rand() % 4;
  bool foundEmpty = false;
  while (!foundEmpty && counter < 7) {
    switch (counter) {
      case 0:
      case 4:
        if (xCoord > 0 && !matrix[xCoord - 1][yCoord]) {
          matrix[xCoord - 1][yCoord] = new Ant(matrix, matrixSize, xCoord - 1, yCoord);
          foundEmpty = true;
        }
        break;

      case 1:
      case 5:
        if (yCoord < matrixSize - 1 && !matrix[xCoord][yCoord + 1]) {
          matrix[xCoord][yCoord + 1] = new Ant(matrix, matrixSize, xCoord, yCoord + 1);
          foundEmpty = true;
        }
        break;

      case 2:
      case 6:
        if (xCoord < matrixSize - 1 && !matrix[xCoord + 1][yCoord]) {
          matrix[yCoord + 1][xCoord] = new Ant(matrix, matrixSize, yCoord + 1, xCoord);
          foundEmpty = true;
        }
        break;

      case 3:
        if (xCoord > 0 && !matrix[yCoord][xCoord - 1]) {
          matrix[xCoord][yCoord - 1] = new Ant(matrix, matrixSize, xCoord, yCoord - 1);
          foundEmpty = true;
        }
        break;

      // default:
      //   break;
    }
    counter++;
  }
  return foundEmpty;
};

bool Ant::move() {
  int direction = rand() % 4;
  bool moved = false;
    switch (direction) {
      case 0:
        if (xCoord != 0 && !matrix[xCoord - 1][yCoord]) {
          matrix[xCoord - 1][yCoord] = this;
          matrix[xCoord][yCoord] = 0;
          moved = true;
        }
        break;

      case 1:
        if (yCoord != matrixSize - 1 && !matrix[xCoord][yCoord + 1]) {
          matrix[xCoord][yCoord + 1] = this;
          matrix[xCoord][yCoord] = 0;
          moved = true;
        }
        break;

      case 2:
        if (xCoord != matrixSize - 1 && !matrix[xCoord + 1][yCoord]) {
          matrix[xCoord + 1][yCoord] = this;
          matrix[xCoord][yCoord] = 0;
          moved = true;
        }
        break;

      case 3:
        if (yCoord != 0 && !matrix[xCoord][yCoord - 1]) {
          matrix[xCoord][yCoord - 1] = this;
          matrix[xCoord][yCoord] = 0;
          moved = true;
        }
        break;

      // default:
      //   break;
    }
  return moved;
};
