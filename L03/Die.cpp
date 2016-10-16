/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/17/2016

** Description: Lab 3 - Part of a simplified game of War, with dice.
This is the implementation file for the Die class, which includes
all the source code for the functions the class contains.

*********************************************************************/

#include <cstdlib>
#include <ctime>
#include "Die.hpp"

/*********************************************************************

** Description: Die()

** This is the default constructor that sets the number of sides to 6,
and generates a random number seed for the rand function

*********************************************************************/

Die::Die() {
  numSides = 6;
  srand (std::time(NULL));
};

/*********************************************************************

** Description: Die(int)

** This is a constructor that sets the number of sides to a user specified
number, and generates a random number seed for the rand function

*********************************************************************/

Die::Die(int sides) {
  numSides = sides;
  srand (std::time(NULL));
};

/*********************************************************************

** Description: getSides()

** Returns the number of sides of the die 

*********************************************************************/

int Die::getSides() {
  return numSides;
}

/*********************************************************************

** Description: roll()

** This is the function that rolls the die. Generates a random number
from 1 to numSides and returns it.

*********************************************************************/

int Die::roll() {
    int rollNum = rand() % numSides + 1;
    return rollNum;
};
