/*********************************************************************

** Program Filename: BlueMen.hpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the interface file for the BlueMen derived class,
which includes the class, variable and function declarations.

*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

// Defines the interface of the BlueMen class
class BlueMen
{

  public:
    BlueMen();
    bool defend();
};

#endif
