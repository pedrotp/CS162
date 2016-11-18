/*********************************************************************

** Program Filename: Medusa.hpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Assignment 4 - Part of a fantasy dice tournament game.
This is the interface file for the Medusa derived class,
which includes the class, variable and function declarations.

*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

// Defines the interface of the Medusa class
class Medusa : public Creature
{

  public:
    Medusa();
    int attack();
};

#endif
