/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/30/2016

** Description: Lab 5 -

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
    Doodlebug(Critter ***matrPtr, int matrSize, int startX, int startY);
    bool breed();
    bool move();
    bool eat();
    ~Doodlebug() {};
};
#endif
