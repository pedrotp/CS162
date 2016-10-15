/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/15/2016

** Description: Lab 3 - Part of a simplified game of War, with dice.
This is the interface file for the LoadeDie class, which includes the
class, variable and function declarations.

*********************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class LoadedDie : public Die {

  private:
    int oddsMultiplier; // how many times more likely that the die will land on the largest number (i.e. 3x, 5x)

  public:
    LoadedDie(int sides);
    int roll();

};

#endif
