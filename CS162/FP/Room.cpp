/*********************************************************************

** Program Filename: Room.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the implementation file
for the Room abstract base class, which includes the source code for
all the functions in the class.

*********************************************************************/

#include "Room.hpp"

Room::Room(Player* p1) {

  p = p1;

};

void Room::setDoor(std::pair<std::string, Room*> door) {

  doors.insert(door);

};
