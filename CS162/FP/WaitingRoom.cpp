/*********************************************************************

** Program Filename: WaitingRoom.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the implementation file
for the WaitingRoom class, which is derived from the Room class. This
file includes the source code for all the functions in the class.

*********************************************************************/

#include "WaitingRoom.hpp"

WaitingRoom::WaitingRoom(Player* p1) : Room(p1){

};

Room* WaitingRoom::play() {

  Room* nextroom = 0;

  std::cout << "\nWelcome to the DMV waiting room!" << std::endl;
  std::cout << "Please wait, I will be with you in a moment\n" << std::endl;

  // wait
  int waitTime = (rand() % 6);
  for (int i = 0; i < waitTime; i++) {
      std::cout << "...";
      usleep(1000000);
  }
  std::cout << std::endl;

  std::cout << "\nThanks for waiting. How can I help you?" << std::endl;
  // "I'd like to get a new driver's license"
  // "I'd like to renew my existing license"
  // "Never mind (head to another room)"

  return nextroom;

};
