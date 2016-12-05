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

  DMVtime = 0;

  rooms["Waiting Room"] = new WaitingRoom(&p);
  rooms["Driving Test"] = new DrivingTest(&p);
  rooms["Forms Dept"] = new FormsDept(&p);
  rooms["Photo Lab"] = new PhotoLab(&p);
  rooms["Vision Test"] = new VisionTest(&p);
  rooms["Written Test"] = new WrittenTest(&p);

  for (std::map<std::string, Room*>::iterator it1 = rooms.begin(); it1 != rooms.end(); it1++) {
    for (std::map<std::string, Room*>::iterator it2 = rooms.begin(); it2 != rooms.end(); it2++) {
      if (it1->first != it2->first) {
        it1->second->setDoor(*it2);
      }
    }
  }

  currentRoom = rooms["Waiting Room"];

};

Game::~Game() {

  for (std::map<std::string, Room*>::iterator it = rooms.begin(); it != rooms.end(); it++) {
    delete it->second;
  }

};

void Game::showHeader() {
  std::cout << "\033[2J\033[1;1H";
  std::cout << "The current time is 5:" << std::setw(2) << std::setfill('0') << DMVtime << " PM" << std::endl;
  std::cout << "Inventory:";
  if (p.inventory.empty()) {
    std::cout << "(empty)";
  } else {
    for (std::set<std::string>::iterator it = p.inventory.begin(); it != p.inventory.end(); it++) {
      std::cout << " " << *it;
    }
  }
  std::cout << std::endl;
};

void Game::play() {

  while (currentRoom != 0 && DMVtime != 60) {
    showHeader();
    currentRoom = currentRoom->play();
    DMVtime++;
  }
  if (p.inventory.find("drivers_license") != p.inventory.end()) {
    std::cout << "\nCongrats on getting your driver's license! Drive safely.\n" << std::endl;
  } else if (currentRoom == 0) {
    std::cout << "\nGood bye! Come back any time to try to get your driver's license again.\n" << std::endl;
  } else if (DMVtime == 60) {
    std::cout << "\nOh no, you're out of time! It's 6:00 PM and the DMV is closed.\n" << std::endl;
  }

};
