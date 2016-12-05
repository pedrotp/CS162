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

Room* Room::nextStep() {

  Room* nextR = 0;

  int i = 0;
  std::cout << "\nWhere do you want to go next?\n" << std::endl;
  for (std::map<std::string, Room*>::iterator it = doors.begin(); it != doors.end(); it++) {
    std::cout << i + 1 << ": " << it->first << "\n";
    i++;
  }
  std::cout << "(Press 0 to quit the game)\n" << std::endl;
  int choice = getInt(0, doors.size());
  if (choice) {
    std::map<std::string, Room*>::iterator it = doors.begin();
    std::advance(it, choice - 1);
    nextR = it->second;
  }

  return nextR;

};
