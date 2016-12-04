/*********************************************************************

** Program Filename: FormsDept.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the interface file for
the FormsDept class, which is a subclass of Room. This file includes
all the class, variable and function declarations.

*********************************************************************/

#ifndef FORMSDEPT_HPP
#define FORMSDEPT_HPP

#include "Room.hpp"

// Defines the interface of the FormsDept class
class FormsDept : public Room
{

  public:
    FormsDept(Player* p1);
    Room* play();

};

#endif
