/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/17/2016

** Description: Lab 3 - Part of a simplified game of War, with dice.
This is the interface file for the LoadeDie class, which includes the
class, variable and function declarations.

*********************************************************************/

#ifndef LOADEDDIE_HPP
#define LOADEDDIE_HPP

#include "Die.hpp"

class LoadedDie : public Die {

  public:
    LoadedDie(int sides);
    int roll();

};

#endif
