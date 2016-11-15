/*********************************************************************

** Program Filename: Creature.hpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the interface file for the Creature abstract base class,
which includes some of the class, variable and function declarations.

*********************************************************************/

#include <cstdlib> // rand()
#include <ctime> // std::time
#include <iostream>
#include <string>

#ifndef CREATURE_HPP
#define CREATURE_HPP

// Defines the interface of the Creature class
class Creature
{
  protected:
    int attackDice[2]; // pos 0 represents the number of dice, and pos 1 the number of sides
    int defenseDice[2]; // pos 0 represents the number of dice, and pos 1 the number of sides
    int armor;
    int strength;
    std::string cType;

  public:
    Creature(int attackNum, int attackSides, int defenseNum, int defenseSides, int armorPts, int strengthPts, std::string creatureType);
    std::string type();
    virtual int attack();
    virtual bool defend(int attackRes);
};

#endif
