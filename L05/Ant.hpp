/*********************************************************************

** Program Filename: Ant.hpp

** Author: Pedro Torres-Picon

** Date: 11/02/2016

** Description: Lab 5 - Part of a predator/prey simulation.
This is the implementation file for the Ant class, which is derived 
from the Critter abstract class. This file includes some of the class,
variable and function declarations.

*********************************************************************/

#include "Critter.hpp"

#ifndef ANT_HPP
#define ANT_HPP

// Defines the interface of the Ant class
class Ant : public Critter
{
  public:
    Ant(Critter ***matrPtr, int matrSize, int startX, int startY, int startStep = 0);
    bool breed();
    bool move();
    ~Ant() {};

};

#endif
