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

  s1 = s2 = s3 = s4 = s5 = 0;
  p = p1;

};

void Room::setRooms(Room* p1, Room* p2, Room* p3, Room* p4, Room* p5); {

  s1 = p1;
  s2 = p2;
  s3 = p3;
  s4 = p4;
  s5 = p5;

};
