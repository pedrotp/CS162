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

void WaitingRoom::showReqs() {
  std::cout << "Here are the requirements I need to issue you a license:" << '\n';
  std::cout << "\n- Form 57B, which validates your identity" << '\n';
  std::cout << "- Signed Vision Certificate from our Optometrist" << '\n';
  std::cout << "- Form 409H, which shows a grade of 80% or more on the Written Test" << '\n';
  std::cout << "- Form 90A, signed by your instructor, which confirms you passed the Driving Test" << '\n';
  std::cout << "\n** All forms can be obtained in the forms dept with the proper documents **\n" << '\n';
  std::cout << "Come back with all of these requirements and I'll give you your license!\n" << std::endl;
};

Room* WaitingRoom::play() {

  std::cout << "Current room: Waiting Room\n\n" << std::endl;
  std::cout << "Please wait, I will be with you in a moment\n" << std::endl;

  // wait
  int waitTime = (rand() % 4 + 3);
  for (int i = 0; i < waitTime; i++) {
      std::cout << "..." << std::endl;
      usleep(1000000);
  }
  std::cout << std::endl;

  std::cout << "Thanks for waiting. How can I help you?\n" << std::endl;

  if (p->currentTime == 0) {
    std::cout << "A driver's license? Sure! I can help with that" << std::endl;
    showReqs();
  } else if (!checkInv()) {
    std::cout << "You again?! I thought I told you to come back when you had ALL the requirements\n" << '\n';
    std::cout << "1: Can I hear the requirements again?" << '\n';
    std::cout << "2: OK, I'll be back\n" << std::endl;
    if (getInt(1,2) == 1) {
      showReqs();
    }
  } else {
    std::cout << "You again?! ... Oh, wait, it looks like you have all the requirements...\n" << '\n';
    std::cout << "Why didn't you say so?! Please wait...\n" << '\n';
    for (int i = 0; i < 5; i++) {
        std::cout << "..." << std::endl;
        usleep(1000000);
    }
    p->inventory.insert("drivers_license");
    std::cout << "\nOk, here's your driver's license:\n\n";
    std::cout << "___________________________________________________\n";
    std::cout << "!          !                                      !\n";
    std::cout << "! //////// !           DRIVER'S LICENSE           !\n";
    std::cout << "! !  _  _! !     Name:__________________________  !\n";
    std::cout << "!(! (.)(.) !  Address:__________________________  !\n";
    std::cout << "! !   _\\_! !  Date of birth:____________________  !\n";
    std::cout << "! !_____/   !   Height:______ Weight:_______ Lbs. !\n";
    std::cout << "! //    \\\\  !  Color Eyes:______ Color hair:____  !\n";
    std::cout << "!----------  LICENSE# PRNDSL1234OD                !\n";
    std::cout << "!_________________________________________________!\n";
    std::cout << std::endl;
    return 0;
  }

  return nextStep();

};
