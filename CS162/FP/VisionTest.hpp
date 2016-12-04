/*********************************************************************

** Program Filename: VisionTest.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the interface file for
the VisionTest class, which is a subclass of Room. This file includes
all the class, variable and function declarations.

*********************************************************************/

#ifndef VISIONTEST_HPP
#define VISIONTEST_HPP

#include "Room.hpp"

// Defines the interface of the VisionTest class
class VisionTest : public Room
{

  public:
    VisionTest(Player* p1);
    Room* play();

};

#endif
