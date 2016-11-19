/*********************************************************************

** Program Filename: Creature.cpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Assignment 4 - Part of a fantasy dice tournament game.
This is the implementation file for the Creature abstract base class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "Creature.hpp"

/*********************************************************************

** Description: Creature()

** This is the constructor for the abstract base class Creature, which
sets some internal values according to provided arguments

*********************************************************************/

Creature::Creature(int attackNum, int attackSides, int defenseNum, int defenseSides, int armorPts, int strengthPts, std::string creatureName) {

  // srand (std::time(NULL));

  attackDice[0] = attackNum;
  attackDice[1] = attackSides;
  defenseDice[0] = defenseNum;
  defenseDice[1] = defenseSides;
  armor = armorPts;
  strength = strengthPts;
  cName = creatureName;

};


/*********************************************************************

** Description: name()

** Basic getter that returns the creature's name as a string

*********************************************************************/

std::string Creature::name() {

  return cName;

};

/*********************************************************************

** Description: setName()

** Basic setter that sets the creature's name to a user supplied string

*********************************************************************/

void Creature::setName(std::string creatureName) {

  cName = creatureName;

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

  return result;

};
