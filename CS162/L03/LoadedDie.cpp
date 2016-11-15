/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/17/2016

** Description: Lab 3 - Part of a simplified game of War, with dice.
This is the implementation file for the LoadedDie class, which includes
all the source code for the functions the class contains.

*********************************************************************/

#include <cstdlib>
#include "LoadedDie.hpp"

/*********************************************************************

** Description: LoadedDie(int)

** This is the default constructor, which passes the int argument to
the constructor fo the Die() class

*********************************************************************/

LoadedDie::LoadedDie(int sides) : Die(sides) {};

/*********************************************************************

** Description: roll()

** This function redefines the roll() function from the Die class to
implement the increased odds for a higher roll

*********************************************************************/

int LoadedDie::roll() {
  int sidesNum = getSides();
  int rollResult = rand() % (2 * sidesNum) + 1;
  if (rollResult > sidesNum) {
    rollResult = sidesNum;
  }
  return rollResult;
};
