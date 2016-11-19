/*********************************************************************

** Program Filename: BlueMen.cpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Assignment 4 - Part of a fantasy dice tournament game.
This is the implementation file for the BlueMen derived class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "BlueMen.hpp"

/*********************************************************************

** Description: BlueMen()

** This is the constructor for the derived class BlueMen, which
calls the base class constructor, and sets some internal values. It
also reimplements the defend function to create the Mob feature and
make sure that the class loses a die when strength is at 8 and 4.

*********************************************************************/

BlueMen::BlueMen() : Creature(2, 10, 3, 6, 3, 12, "Blue Men") {};

bool BlueMen::defend(int attackRes) {

  bool result = Creature::defend(attackRes);

  // Mob Feature
  if ((strength == 8 && defenseDice[0] == 3) || (strength == 4 && defenseDice[0] == 2)) {
    defenseDice[0]--;
  }

  return result;

};
