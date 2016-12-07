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
#include <iomanip>
#include <ctime>
#include <cstdlib> // rand(), srand()
#include <ctime> // std::time
#include <unistd.h> // usleep
#include "helpers.hpp"

class Room;

struct Player {

  int currentTime; // holds the time at the DMV
  std::set<std::string> inventory; // holds all the items in the player's inventory

};

// Defines the interface of the Room class
class Room
{

  protected:
    Player* p;
    std::map<std::string, Room*> doors; // holds the pointers to travel between rooms

  public:
    Room(Player* p1);
    virtual ~Room() {};
    void setDoor(std::pair<std::string, Room*> door);
    Room* nextStep();
    bool checkInv(std::string item = "license_reqs"); // checks if an item is in the inventory
    virtual Room* play() = 0; // this function runs the mini-games in each room subclass

};

#endif
