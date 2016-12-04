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

#include <iostream>
#include <map>
#include <string>

// Defines the interface of the Game class
class Game
{
  protected:
    struct Player {
      std::string name;
      std::map<std::string, bool> goals;
      std::set<std::string> inventory;
      Player(std::string n) { // constructor
        name = n;
        license = false;
      }
    };
    Player *p;

  public:
    Game();
    ~Game();
    void play();

};

#endif
