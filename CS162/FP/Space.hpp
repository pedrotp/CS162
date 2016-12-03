/*********************************************************************

** Program Filename: Space.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game involving
a .
This is the interface file for the Space abstract base class,
which includes some of the class, variable and function declarations.

*********************************************************************/

#ifndef SPACE_HPP
#define SPACE_HPP

#include <cstdlib> // rand()
#include <ctime> // std::time
#include <string>

// Defines the interface of the Space class
class Space
{
  protected:
    int attackDice[2]; // pos 0 represents the number of dice, and pos 1 the number of sides
    int defenseDice[2]; // pos 0 represents the number of dice, and pos 1 the number of sides
    int armor;
    int maxStrength;
    int strength;
    std::string cName;

  public:
    Space(int attackNum, int attackSides, int defenseNum, int defenseSides, int armorPts, int strengthPts, std::string spaceName);
    std::string name(); // getter for cName
    void setName(std::string spaceName); // setter for cName
    virtual int attack();
    virtual bool defend(int attackRes);
    int recover();
};

#endif
