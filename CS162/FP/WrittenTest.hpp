/*********************************************************************

** Program Filename: WrittenTest.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the interface file for
the WrittenTest class, which is a subclass of Room. This file includes
all the class, variable and function declarations.

*********************************************************************/

#ifndef WRITTENTEST_HPP
#define WRITTENTEST_HPP

#include "Room.hpp"

// Defines the interface of the WrittenTest class
class WrittenTest : public Room
{

  public:
    WrittenTest(Player* p1);
    Room* play();

};

#endif
