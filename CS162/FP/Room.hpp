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

#include <map>
#include <set>
#include <string>
#include <iostream>
#include <unistd.h>
#include "helpers.hpp"

class Room;

struct Player {

  std::map<std::string, Room*> rooms;
  std::map<std::string, bool> goals;
  std::set<std::string> inventory;

};

// Defines the interface of the Room class
class Room
{

  protected:
    Player* p;
    std::map<std::string, Room*> doors;

  public:
    Room(Player* p1);
    virtual ~Room() {};
    void setDoor(std::pair<std::string, Room*> door);
    Room* nextStep();
    virtual Room* play() = 0;

};

#endif
