/*********************************************************************

** Program Filename: Vampire.hpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the interface file for the Vampire derived class,
which includes the class, variable and function declarations.

*********************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "Creature.hpp"

// Defines the interface of the Vampire class
class Vampire : public Creature
{

  public:
    Vampire();
    bool defend(int attackRes);
};

#endif
