/*********************************************************************

** Program Filename: Game.cpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the implementation file
for the Game class, which includes the source code for all the
functions in the class.

*********************************************************************/

#include "Game.hpp"

Game::Game() {

  rooms["Waiting Room"] = new WaitingRoom(&p);
  rooms["Driving Test"] = new DrivingTest(&p);
  rooms["Forms Dept"] = new FormsDept(&p);
  rooms["Photo Lab"] = new PhotoLab(&p);
  rooms["Vision Test"] = new VisionTest(&p);
  rooms["Written Test"] = new WrittenTest(&p);

  for (std::map<std::string, Room*>::iterator it1 = rooms.begin(); it1 != rooms.end(); ++it1) {
    for (std::map<std::string, Room*>::iterator it2 = rooms.begin(); it2 != rooms.end(); ++it2) {
      if (it1->first != it2->first) {
        it1->second->setDoor(*it2);
      }
    }
  }

  currentRoom = rooms["Waiting Room"];

};

Game::~Game() {

  for (std::map<std::string, Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it) {
    delete it->second;
  }

}
void Game::play() {

  while (currentRoom != 0) {
    currentRoom = currentRoom->play();
  }

};
