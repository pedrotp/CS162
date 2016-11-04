/*********************************************************************

** Program Filename: Vampire.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the implementation file for the Vampire derived class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "Vampire.hpp"

/*********************************************************************

** Description: Vampire()

** This is the constructor for the derived class Vampire, which
calls the base class constructor, and sets some internal values

*********************************************************************/

Vampire::Vampire() : Critter(1, 12, 1, 6, 1, 18) {};

bool Vampire::defend(int attackRes) {

  bool result = true;
  int test = rand() % 100 + 1;

  if (test > 50) { // 50% of the time the attack is ignored

    // attackRes -= armor;
    // for (int i = 0; i < defenseDice[0]; i++) {
    //   attackRes -= rand() % defenseDice[1] + 1;
    // }
    // strength -= attackRes;
    // if (strength < 1) {
    //   result = false; // if this creature has died, return false
    // }

    result = Critter::defend(attackRes);

  }

  return result;

};
