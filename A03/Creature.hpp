/*********************************************************************

** Program Filename: Creature.hpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the interface file for the Creature abstract base class,
which includes some of the class, variable and function declarations.

*********************************************************************/

#include <string>
#include <cstdlib>
#include <ctime>

#ifndef CREATURE_HPP
#define CREATURE_HPP

// Defines the interface of the Creature class
class Creature
{
  protected:
    int[2] attackDice; // pos 0 represents the number of dice, and pos 1 the number of sides
    int[2] defenseDice; // pos 0 represents the number of dice, and pos 1 the number of sides
    int armor;
    int strength;

  public:
    Creature(int attackNum, int attackSides, int defendNum, int defendSides, int armorPts, int strengthPts);
    int attack();
    bool defend(int attackStrength);
};

#endif
