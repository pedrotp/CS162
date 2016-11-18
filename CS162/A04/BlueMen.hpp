/*********************************************************************

** Program Filename: BlueMen.hpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Assignment 4 - Part of a fantasy dice tournament game.
This is the interface file for the BlueMen derived class,
which includes the class, variable and function declarations.

*********************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

// Defines the interface of the BlueMen class
class BlueMen : public Creature
{

  public:
    BlueMen();
    bool defend(int attackRes);
};

#endif
