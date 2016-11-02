/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/30/2016

** Description: Lab 5 -

*********************************************************************/

#include "Critter.hpp"

#ifndef ANT_HPP
#define ANT_HPP

// Defines the interface of the Ant class
class Ant : public Critter
{
  public:
    Ant(Critter ***matrPtr, int matrSize, int startX, int startY);
    bool breed();
    bool move();
    ~Ant() {};

};

#endif
