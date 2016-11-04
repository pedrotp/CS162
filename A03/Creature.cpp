/*********************************************************************

** Program Filename: Creature.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the implementation file for the Creature abstract base class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "Creature.hpp"

/*********************************************************************

** Description: Creature()

** This is the constructor for the abstract base class Creature, which
sets some internal values according to provided arguments

*********************************************************************/

Creature::Creature(int attackNum, int attackSides, int defenseNum, int defenseSides, int armorPts, int strengthPts) {

  srand (std::time(NULL));

  attackDice[0] = attackNum;
  attackDice[1] = attackSides;
  defenseDice[0] = defenseNum;
  defenseDice[1] = defenseSides;
  armor = armorPts;
  strength = strengthPts;

};

int Creature::attack() {
  int result = 0;
  for (int i = 0; i < attackDice[0]; i++) {
    result += rand() % attackDice[1] + 1;
  }
  return result;
};

bool Creature::defend(int attackRes){

  bool result = true;
  attackRes -= armor;
  for (int i = 0; i < defenseDice[0]; i++) {
    attackRes -= rand() % defenseDice[1] + 1;
  }
  strength -= attackRes;
  if (strength < 1) {
    result = false;
  }
  return result;

};
