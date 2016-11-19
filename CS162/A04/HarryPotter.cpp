/*********************************************************************

** Program Filename: HarryPotter.cpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Assignment 4 - Part of a fantasy dice tournament game.
This is the implementation file for the HarryPotter derived class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "HarryPotter.hpp"

/*********************************************************************

** Description: HarryPotter()

** This is the constructor for the derived class HarryPotter, which
calls the base class constructor, and sets some internal values. It
also reimplements the defend function, to make sure harry's strength
points go back to 20 the first time he dies.

*********************************************************************/

HarryPotter::HarryPotter() : Creature(2, 6, 2, 6, 0, 10, "Harry Potter") {
  hasDied = false;
};

bool HarryPotter::defend(int attackRes) {

  bool result = Creature::defend(attackRes);

  if (!result && !hasDied) {

    hasDied = true;
    strength = 20;
    result = true;
    
  }

  return result;

};
