/*********************************************************************

** Program Filename: VisionTest.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the implementation file
for the VisionTest class, which is derived from the Room class. This
file includes the source code for all the functions in the class.

*********************************************************************/

#include "VisionTest.hpp"

/*********************************************************************

** Description: VisionTest()

** This is the constructor for the VisionTest class, which
passes the p variable to the constructor for the Room abstract
base class

*********************************************************************/

VisionTest::VisionTest(Player* p1) : Room(p1){
};

/*********************************************************************

** Description: play()

** This function runs the VisionTest mini-game, which asks the user to
"read" letters and gives them a certificate if they get all of them
right

*********************************************************************/

Room* VisionTest::play() {

  std::cout << "Current room: Vision Test Room\n\n" << std::endl;

  std::cout << "Welcome, I'm your optometrist\n" << std::endl;

  if (!checkInv("vision_cert")) { // player may only complete this activity once

    if (checkInv("form_57b")) {
      bool correct = true;
      std::cout << "Please sit here, look at the letters in front of you, and read them back to me one by one\n" << std::endl;

      int i = 0;
      while (i < 8 && correct) {

        char ch = rand() % 26 + 97;
        std::cout << ch << std::endl;
        char char_input = getChar();
        if (char_input != ch) {
          correct = false;
        }
        i++;

      }
      p->currentTime += 10;
      if (correct) {

        std::cout << "Great job! You have 20/20 vision. Here is your certificate." << '\n';
        if (p->inventory.size() < 4) p->inventory.insert("vision_cert");
        std::cout << "\n[vision_cert added to inventory]\n" << std::endl;

      } else {

        std::cout << "Whoops! Looks like you might need glasses. Come back later and try again." << std::endl;

      }

    } else {

      std::cout << "Sorry! I can't give you an eye exam without Form 57B (Proof of ID). I wouldn't know who you are!\n";
      std::cout << "Please come back when you have the proper form. You can get it in the Forms Department\n" << std::endl;

    }

  } else {

    std::cout << "\nHm, looks like you already have your Vision Certificate. You're done here!\n" << std::endl;

  }

  return nextStep();

};
