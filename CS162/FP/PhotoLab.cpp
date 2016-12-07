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

/*********************************************************************

** Description: PhotoLab()

** This is the constructor for the PhotoLab class, which
passes the p variable to the constructor for the Room abstract
base class

*********************************************************************/

PhotoLab::PhotoLab(Player* p1) : Room(p1){
};

/*********************************************************************

** Description: play()

** This function runs the PhotoLab mini-game, which allows the user
to "take a picture", provided they have proper photo ID

*********************************************************************/

Room* PhotoLab::play() {

  std::cout << "Current room: Photo Lab\n\n" << std::endl;

  std::cout << "Welcome to the photo lab, I'd be happy to take your photo" << std::endl;

  if (!checkInv("license_photo") && !checkInv("form_57b")) {

    std::cout << "Do you have a valid form of ID? (y/n)\n" << std::endl;

    if (getYesNo()) {

      std::cout << "\nGreat. Say cheese!\n" << '\n';
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
      std::cout << "\n!----------!\n";
      std::cout << "! //////// !\n";
      std::cout << "! !  _  _! !\n";
      std::cout << "!(! (.)(.) !\n";
      std::cout << "! !   _\\_! !\n";
      std::cout << "! !_____/  !\n";
      std::cout << "! //    \\\\ !\n";
      std::cout << "!----------!\n";
      if (p->inventory.size() < 4) p->inventory.insert("license_photo");
      std::cout << "\n[license_photo added to inventory]" << std::endl;
      p->currentTime += 5;

    } else {

      std::cout << "\nSorry! Can't take your photo without ID. Come back when you have it!\n" << std::endl;

    }

  } else {

    std::cout << "\nHm, looks like you've already taken your photo. You're done here!" << std::endl;

  }

  return nextStep();

};
