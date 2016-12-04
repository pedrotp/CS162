/*********************************************************************

** Program Filename: Room.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the interface file for
the Room abstract base class, which includes some of the class,
variable and function declarations.

*********************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include "Game.hpp"

// Defines the interface of the Room class
class Room
{

  protected:
    Player* p;
    Room* s1;
    Room* s2;
    Room* s3;
    Room* s4;
    Room* s5;

  public:
    Room(Player* p1);
    virtual ~Room() {};
    void setRooms(Room* p1 = 0, Room* p2 = 0, Room* p3 = 0, Room* p4 = 0, Room* p5 = 0);
    virtual Room* play() = 0;

};

#endif
