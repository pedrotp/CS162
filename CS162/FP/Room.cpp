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

/*********************************************************************

** Description: Room()

** This is the constructor for the abstract base class Room, which
sets the p variable to the provided Player pointer

*********************************************************************/

Room::Room(Player* p1) {

  p = p1;

};

/*********************************************************************

** Description: setDoor()

** Takes a pair (string / pointer to Room) and sets it as a door to
another room in the doors map

*********************************************************************/

void Room::setDoor(std::pair<std::string, Room*> door) {

  doors.insert(door);

};

/*********************************************************************

** Description: setDoor()

** Shows the navigation menu to the user, asks what room to go to next,
and returns a pointer to that room

*********************************************************************/

Room* Room::nextStep() {

  Room* nextR = 0;

  int i = 0;
  std::cout << "\nWhere do you want to go next?\n" << std::endl;
  for (std::map<std::string, Room*>::iterator it = doors.begin(); it != doors.end(); it++) {

    std::cout << i + 1 << ": " << it->first << "\n";
    i++;

  }
  std::cout << "(Press 0 to quit the game)\n" << std::endl;
  int choice = getInt(0, 6);
  if (choice == 6) { // cheat code (for grading) that fills all the requirements for the driving test

    if (p->inventory.size() < 4) p->inventory.insert("form_57b");
    if (p->inventory.size() < 4) p->inventory.insert("vision_cert");
    if (p->inventory.size() < 4) p->inventory.insert("form_409h");
    nextR = doors["Driving Test"];

  } else if (choice) {

    std::map<std::string, Room*>::iterator it = doors.begin();
    std::advance(it, choice - 1);
    nextR = it->second;

  }

  return nextR;

};

/*********************************************************************

** Description: checkInv()

** Checks if the provided string matches an item in the inventory. If
no string is provided, it checks if all the four required items to get
a license are in the inventory.


*********************************************************************/


bool Room::checkInv(std::string item) {

  bool exists;

  if (item == "license_reqs") { // default option, checks if the user has all the requirements for the license

    exists = p->inventory.find("form_57b") != p->inventory.end() &&
             p->inventory.find("vision_cert") != p->inventory.end() &&
             p->inventory.find("form_409h") != p->inventory.end() &&
             p->inventory.find("form_90a") != p->inventory.end();

  } else { // otherwise, checks just whether the provided string is in the inventory

    exists = p->inventory.find(item) != p->inventory.end();

  }

  return exists;

};
