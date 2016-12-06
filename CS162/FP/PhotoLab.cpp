/*********************************************************************

** Program Filename: PhotoLab.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the implementation file
for the PhotoLab class, which is derived from the Room class. This
file includes the source code for all the functions in the class.

*********************************************************************/

#include "PhotoLab.hpp"

PhotoLab::PhotoLab(Player* p1) : Room(p1){

};

Room* PhotoLab::play() {

  std::cout << "Current room: Photo Lab\n\n" << std::endl;

  std::cout << "Welcome to the photo lab, I'd be happy to take your photo" << std::endl;
  std::cout << "Do you have a valid form of ID?\n" << std::endl;

  if (getYesNo()) {

    std::cout << "Great. Say cheese!\n" << '\n';
    usleep(1000000);
    std::cout << "    \\ | /\n";
    std::cout << "   '  _  '\n";
    std::cout << "  -  |_|  -\n";
    std::cout << "   ' | | '\n";
    std::cout << "   _,_|___\n";
    std::cout << "  |   _ []|\n";
    std::cout << "  |  (O)  |\n";
    std::cout << "  |_______|\n";
    std::cout << std::endl;
    usleep(1000000);
    std::cout << "Here's your photo, thanks for coming in!\n" << std::endl;
    p->inventory.insert("license_photo");
    std::cout << "[license_photo added to inventory]" << std::endl;
    p->currentTime += 5;

  } else {

    std::cout << "Sorry! Can't take your photo without ID. Come back when you have it!\n" << std::endl;

  }

  return nextStep();

};
