/*********************************************************************

** Program Filename: HarryPotter.hpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Assignment 4 - Part of a fantasy dice tournament game.
This is the interface file for the HarryPotter derived class,
which includes the class, variable and function declarations.

*********************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

// Defines the interface of the HarryPotter class
class HarryPotter : public Creature
{
  private:
    bool hasDied; // variable to check if Harry has already died once

  public:
    HarryPotter();
    bool defend(int attackRes);
};

#endif
