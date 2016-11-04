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

BlueMen::BlueMen() : Critter(2, 10, 3, 6, 3, 12) {};

bool BlueMen::defend(int attackRes) {

  bool result = true;

  attackRes -= armor;
  for (int i = 0; i < defenseDice[0]; i++) {
    attackRes -= rand() % defenseDice[1] + 1;
  }
  strength -= attackRes;

  if (strength < 1) {
    strength = 0;
    result = false; // if this creature has died, return false
  } else if (strength < 12 && strength % 4 == 0) { // Mob feature
    defenseDice[0]--;
  }

  return result;

};
