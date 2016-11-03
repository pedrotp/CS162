/*********************************************************************

** Program Filename: Critter.cpp

** Author: Pedro Torres-Picon

** Date: 11/02/2016

** Description: Lab 5 - Part of a predator/prey simulation.
This is the implementation file for the Critter abstract base class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "Critter.hpp"

/*********************************************************************

** Description: Critter()

** This is the constructor for the abstract base class Critter, which
sets some internal values and seeds the srand() function with the
clock time

*********************************************************************/

Critter::Critter(Critter ***matrPtr, int matrSize, int startX, int startY, int startStep) {
  srand (std::time(NULL));
  matrix = matrPtr;
  matrixSize = matrSize;
  xCoord = startX;
  yCoord = startY;
  breedCounter = 0;
  stepCounter = startStep;
};

std::string Critter::type() {
  return critterType;
};

/*********************************************************************

** Description: step()

** This function runs one "time step" for a particular instance of
a subclass of Critter

*********************************************************************/

bool Critter::step(int currentStep) {
  bool moved = true;
  if (stepCounter == currentStep) {
    stepCounter++;
    moved = move();
    breedCounter++;
    if (breedCounter == breedSteps) {
      breed();
      breedCounter = 0;
    }
  }
  return moved;
};
