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

Creature::Creature(int attackNum, int attackSides, int defenseNum, int defenseSides, int armorPts, int strengthPts, std::string creatureType) {

  // srand (std::time(NULL));

  attackDice[0] = attackNum;
  attackDice[1] = attackSides;
  defenseDice[0] = defenseNum;
  defenseDice[1] = defenseSides;
  armor = armorPts;
  strength = strengthPts;
  cType = creatureType;

};


/*********************************************************************

** Description: type()

** Basic getter thar returns the creature's type as a string

*********************************************************************/

std::string Creature::type() {

  return cType;

};


/*********************************************************************

** Description: attack()

** This is the base implementation of the attack function, that rolls
the required number of dice for an attack, and returns the result of
the roll

*********************************************************************/

int Creature::attack() {

  int result = 0;

  for (int i = 0; i < attackDice[0]; i++) {
    result += rand() % attackDice[1] + 1;
  }

  return result;

};


/*********************************************************************

** Description: defend()

** This is the base implementation of the defend function, that takes
the result of the attack function, subtracts armor and rolls a defense
number that is also subtracted from the attack number. It then returns
a boolean representing whether the creature was killed or not with
this attack.

*********************************************************************/

bool Creature::defend(int attackRes){

  bool result = true;
  attackRes -= armor;
  for (int i = 0; i < defenseDice[0]; i++) {
    attackRes -= rand() % defenseDice[1] + 1;
  }
  if (attackRes < 1){
    attackRes = 0; // make sure the player never gains strength from defending
  }
  strength -= attackRes;
  if (strength < 1) {
    strength = 0;
    result = false; // if this creature has died, return false
  }
  std::cout << strength << " strength points remaining." << std::endl;
  if (attackRes > 80) {
    std::cout << "GLARE: Medusa has turned you to stone!" << std::endl;
  }
  return result;

};
