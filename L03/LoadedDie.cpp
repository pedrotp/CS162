/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/15/2016

** Description: Lab 3 - Part of a simplified game of War, with dice.
This is the implementation file for the LoadedDie class, which includes
all the source code for the functions the class contains.

*********************************************************************/

#include <cstdlib>
#include "LoadedDie.hpp"

LoadedDie::LoadedDie(int sides) : Die(sides) {};

int LoadedDie::roll() {
  int sidesNum = getSides();
  int rollResult = rand() % (2 * sidesNum) + 1;
  if (rollResult > sidesNum) {
    rollResult = sidesNum;
  }
  return rollResult;
};
