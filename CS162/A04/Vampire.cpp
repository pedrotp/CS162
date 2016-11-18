/*********************************************************************

** Program Filename: Vampire.cpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Assignment 4 - Part of a fantasy dice tournament game.
This is the implementation file for the Vampire derived class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "Vampire.hpp"

/*********************************************************************

** Description: Vampire()

** This is the constructor for the derived class Vampire, which
calls the base class constructor, and sets some internal values. It
also modifies the base defend() function to implement the charm
feature which repels an attack 50% of the time.

*********************************************************************/

Vampire::Vampire() : Creature(1, 12, 1, 6, 1, 18, "Vampire") {};

bool Vampire::defend(int attackRes) {

  bool result = true;
  int test = rand() % 100 + 1;

  if (test > 50) { // 50% of the time the attack is ignored

    // the other 50% of the time the Vampire defends normally
    result = Creature::defend(attackRes);

  } else {
    std::cout << strength << " strength points remaining." << std::endl;
    std::cout << "CHARM: The Vampire has charmed you into not attacking!" << std::endl;
  }

  return result;

};
