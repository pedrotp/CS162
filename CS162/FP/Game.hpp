/*********************************************************************

** Program Filename: Game.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the interface file for
the Game class, which includes some of the class, variable and
function declarations.

*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "DrivingTest.hpp"
#include "FormsDept.hpp"
#include "PhotoLab.hpp"
#include "VisionTest.hpp"
#include "WaitingRoom.hpp"
#include "WrittenTest.hpp"

// Defines the interface of the Game class
class Game
{
  protected:
    Player p;
    std::map<std::string, Room*> rooms;
    Room* currentRoom;

  public:
    Game();
    ~Game();
    void play();

};

#endif
