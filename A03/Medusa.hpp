/*********************************************************************

** Program Filename: Medusa.hpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the interface file for the Medusa derived class,
which includes the class, variable and function declarations.

*********************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

// Defines the interface of the Medusa class
class Medusa
{

  public:
    Medusa();
    int attack();
};

#endif
