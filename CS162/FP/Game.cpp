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

  srand(std::time(NULL));

  p.currentTime = 0;

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
  std::cout << "The current time is 5:" << std::setw(2) << std::setfill('0') << p.currentTime << " PM" << std::endl;
  std::cout << "Inventory: ";
  if (p.inventory.empty()) {
    std::cout << "(empty)";
  } else {
    std::set<std::string>::iterator it = p.inventory.begin();
    std::cout << *it;
    for (it++; it != p.inventory.end(); it++) {
      std::cout << ", " << *it;
    }
    if (p.inventory.size() >= 4) {
      std::cout << " [** inventory full **]" << '\n';
    }
  }
  std::cout << std::endl;
};

void Game::play() {

  std::cout << "\n####################################" << '\n';
  std::cout << "#  ######   ###   ###  ##      ##  #" << '\n';
  std::cout << "#  ##   ##  ## # # ##   ##    ##   #" << '\n';
  std::cout << "#  ##   ##  ##  #  ##    ##  ##    #" << '\n';
  std::cout << "#  ######   ##     ##     ####     #" << '\n';
  std::cout << "####################################\n" << std::endl;

  std::cout << "Hey there! Welcome to the DMV. This game is meant to simulate" << '\n';
  std::cout << "the frustration of getting your license in the DMV.\n" << '\n';
  std::cout << "To play, you move around the different rooms in the DMV gathering" << '\n';
  std::cout << "the requirements for your license.\n" << '\n';
  std::cout << "Pay attention to all the messages in each room to understand" << '\n';
  std::cout << "which challenges to complete first, and what the requirements" << '\n';
  std::cout << "are in order to receive your driver's license.\n" << '\n';
  std::cout << "Lastly, as you move around and complete challenges, keep an" << '\n';
  std::cout << "eye at the top of your screen which includes three important" << '\n';
  std::cout << "pieces of information:" << '\n';
  std::cout << "\n * The current time (remember, the DMV closes at 6:00PM!)" << '\n';
  std::cout << " * Your inventory with a list of items you're currently holding" << '\n';
  std::cout << " * The name of the room you're currently in\n" << '\n';
  std::cout << "Ready?! Press any key to go to the Waiting Room and start the game." << '\n';
  system("read");

  while (currentRoom != 0 && p.currentTime < 60) {
    showHeader();
    currentRoom = currentRoom->play();
    p.currentTime++;
  }
  if (p.inventory.find("drivers_license") != p.inventory.end()) {
    std::cout << "\nCongrats! Drive safely.\n" << std::endl;
  } else if (currentRoom == 0) {
    std::cout << "\nGood bye! Come back any time to try to get your driver's license again.\n" << std::endl;
  } else if (p.currentTime > 60) {
    std::cout << "\nOh no, you're out of time! It's 6:00 PM and the DMV is closed. \n" << std::endl;
  }

};
