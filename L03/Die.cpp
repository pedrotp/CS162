/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/15/2016

** Description: Lab 3 - Part of a simplified game of War, with dice.
This is the implementation file for the Die class, which includes
all the source code for the functions the class contains.

*********************************************************************/

#include <cstdlib>
#include <ctime>
#include "Die.hpp"

Die::Die() {
  numSides = 6;
  srand (std::time(NULL));
};

Die::Die(int sides) {
  numSides = sides;
  srand (std::time(NULL));
};

int Die::getSides() {
  return numSides;
}

int Die::roll() {
    int rollNum = rand() % numSides + 1;
    return rollNum;
};
