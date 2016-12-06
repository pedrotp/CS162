/*********************************************************************

** Program Filename: FormsDept.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the implementation file
for the FormsDept class, which is derived from the Room class. This
file includes the source code for all the functions in the class.

*********************************************************************/

#include "FormsDept.hpp"

FormsDept::FormsDept(Player* p1) : Room(p1){

};

Room* FormsDept::play() {

  std::cout << "Current room: Forms Department\n\n" << std::endl;

  std::cout << "Hi there, can I help you find a form?\n" << '\n';
  std::cout << "1: Form 57B (Proof of ID)" << '\n';
  std::cout << "2: Form 409H (Written Test Certification)" << '\n';
  std::cout << "3: Form 90A (Driving Test Certification)" << '\n';
  std::cout << "0: Never mind...\n" << std::endl;

  switch (getInt(0,3)) {

    case 0:
      break;

    case 1:
      if (checkInv("license_photo")) {

        std::cout << "I see you already have your license photo." << '\n';
        std::cout << "One minute please while I make a copy of your ID and staple the photo to the form." << '\n';
        p->inventory.erase("license_photo");
        usleep(1000000);
        std::cout << "[license_photo removed from inventory]" << '\n';
        p->inventory.insert("form_57b");
        usleep(1000000);
        std::cout << "[form_57b added to inventory]" << std::endl;
        p->currentTime++;

      } else {

        std::cout << "Sorry, before I can give you Form 57B, you need your license photo from the Photo Lab." << '\n';

      }
      break;

    case 2:
      if (checkInv("wtest_results")) {

        std::cout << "Great, I'll need to keep your scores for the Written Test. " << '\n';
        std::cout << "I'll get you that form in a minute." << '\n';
        p->inventory.erase("wtest_results");
        usleep(1000000);
        std::cout << "[wtest_results removed from inventory]" << '\n';
        p->inventory.insert("form_409h");
        usleep(1000000);
        std::cout << "[form_409h added to inventory]" << std::endl;
        p->currentTime++;

      } else {

        std::cout << "Sorry, you need to pass the Written Test before I can give you Form 409H." << '\n';

      }
      break;

    case 3:
      if (checkInv("dtest_signature")) {

        std::cout << "Great, I will attach the signature from your driving instructor to the form." << '\n';
        std::cout << "Please give me a minute while I put everything together." << '\n';
        p->inventory.erase("dtest_signature");
        usleep(1000000);
        std::cout << "[dtest_signature removed from inventory]" << '\n';
        p->inventory.insert("form_90a");
        usleep(1000000);
        std::cout << "[form_90a added to inventory]" << std::endl;
        p->currentTime++;

      } else {

        std::cout << "Sorry, you need to pass the Driving Test before I can give you Form 90A." << '\n';

      }
      break;

  }

  return nextStep();

};
