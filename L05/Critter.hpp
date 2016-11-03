/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/30/2016

** Description: Lab 5 -

*********************************************************************/

#include <string>
#include <cstdlib>
#include <ctime>

#ifndef CRITTER_HPP
#define CRITTER_HPP

// Defines the interface of the Critter class
class Critter
{
  protected:
    int breedSteps; // the number of steps a critter needs to survive before breeding
    int breedCounter; // a counter for the steps since the last breed
    int xCoord; // current x coord for the critter
    int yCoord; // current y coord for the critter
    Critter ***matrix; // internal pointer variable for the matrix where the critter moves around
    int matrixSize; // internal variable to hold the size of matrix
    std::string critterType;
    int stepCounter; // keeps track of the current step so Critters don't move twice

  public:
    Critter(Critter ***matrPtr, int matrSize, int startX, int startY, int startStep = 0);
    std::string type();
    bool step(int currentStep);
    virtual bool move() = 0;
    virtual bool breed() = 0;
    virtual ~Critter() {};
};

#endif
