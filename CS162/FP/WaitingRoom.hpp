/*********************************************************************

** Program Filename: WaitingRoom.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the interface file for
the WaitingRoom class, which is a subclass of Room. This file includes
all the class, variable and function declarations.

*********************************************************************/

#ifndef WAITINGROOM_HPP
#define WAITINGROOM_HPP

#include "Room.hpp"

// Defines the interface of the WaitingRoom class
class WaitingRoom : public Room
{

  public:
    WaitingRoom(Player* p1);
    Room* play();

};

#endif
