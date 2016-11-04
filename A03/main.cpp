/*********************************************************************

** Program Filename: HarryPotter.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the implementation file for the HarryPotter derived class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

#include <iostream>

/*********************************************************************

** Description: main()

** This is the main function that creates a grid and runs the
simulation

*********************************************************************/

int main() {

  bool p1alive = true;
  bool p2alive = true;

  Creature *p1 = new Vampire;
  Creature *p2 = new Medusa;

  while (p1alive && p2alive) {

    p1alive = p1->defend(p2->attack());
    if (p1alive) {
      p2alive = p2->defend(p1->attack());
    }

  }

  std::cout << "P1: " << p1alive << std::endl;
  std::cout << "P2: " << p2alive << std::endl;

  return 0;

};
