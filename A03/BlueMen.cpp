/*********************************************************************

** Program Filename: BlueMen.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the implementation file for the BlueMen derived class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "BlueMen.hpp"

/*********************************************************************

** Description: BlueMen()

** This is the constructor for the derived class BlueMen, which
calls the base class constructor, and sets some internal values

*********************************************************************/

BlueMen::BlueMen() : Creature(2, 10, 3, 6, 3, 12) {};

bool BlueMen::defend(int attackRes) {

  bool result = Creature::defend(attackRes);

  // Mob Feature
  if (strength == 8 && defenseDice[0] == 3 || strength == 4 && defenseDice[0] == 2) {
    defenseDice[0]--;
  }

  return result;

};
