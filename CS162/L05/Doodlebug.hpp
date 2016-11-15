/*********************************************************************

** Program Filename: Doodlebug.hpp

** Author: Pedro Torres-Picon

** Date: 11/02/2016

** Description: Lab 5 - Part of a predator/prey simulation.
This is the implementation file for the Doodlebug class, which is derived
from the Critter abstract class. This file includes some of the class,
variable and function declarations.

*********************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "Critter.hpp"

// Defines the interface of the Doodlebug class
class Doodlebug : public Critter
{
  private:
    int stepsWithoutEating; // a counter for the number of steps since the last meal

  public:
    Doodlebug(Critter ***matrPtr, int matrSize, int startX, int startY, int startStep = 0);
    bool breed();
    bool move();
    bool eat();
    ~Doodlebug() {};
};
#endif
