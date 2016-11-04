/*********************************************************************

** Program Filename: Barbarian.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the implementation file for the Barbarian derived class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "Barbarian.hpp"

/*********************************************************************

** Description: Barbarian()

** This is the constructor for the derived class Barbarian, which
calls the base class constructor, and sets some internal values

*********************************************************************/

Barbarian::Barbarian() : Creature(2, 6, 2, 6, 0, 12) {};
