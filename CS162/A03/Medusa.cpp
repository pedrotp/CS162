/*********************************************************************

** Program Filename: Medusa.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the implementation file for the Medusa derived class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "Medusa.hpp"

/*********************************************************************

** Description: Medusa()

** This is the constructor for the derived class Medusa, which
calls the base class constructor, and sets some internal values. It
also modifies the base attack() function to implement the glare
feature that makes Medusa win if she rolls 12

*********************************************************************/

Medusa::Medusa() : Creature(2, 6, 1, 6, 3, 8, "Medusa") {};

int Medusa::attack() {

  int result = Creature::attack();

  if (result == 12) {
    result = 120;
  }

  return result;

};
