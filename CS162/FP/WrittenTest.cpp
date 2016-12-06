/*********************************************************************

** Program Filename: WrittenTest.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the implementation file
for the WrittenTest class, which is derived from the Room class. This
file includes the source code for all the functions in the class.

*********************************************************************/

#include "WrittenTest.hpp"

WrittenTest::WrittenTest(Player* p1) : Room(p1){

};

Room* WrittenTest::play() {

  std::cout << "Current room: Written Test Room\n\n" << std::endl;

  if (checkInv("form_57b")) {
    bool correct = true;
    std::cout << "Welcome, please take a seat. The test is about to begin.\n" << std::endl;
    usleep(1000000);
    std::cout << "[Written Test in progress...]" << std::endl;
    usleep(3000000);
    int score = rand() % 26 + 75;

    if (score > 80) {

      std::cout << "You passed! You have the knowledge and are ready to hit the road. Here are your test results." << '\n';
      p->inventory.insert("wtest_results");
      std::cout << "[wtest_results added to inventory]\n" << std::endl;

    } else {

      std::cout << "Hm, your score was " << score << ", just shy of 80. Study up and come back to take the test again!" << std::endl;

    }

  } else {

    std::cout << "Sorry! You can't take the Written Test without Form 57B. I wouldn't know who you are!\n";
    std::cout << "Please come back when you have the proper forms. You can get them in the Forms Department.\n" << std::endl;

  }

  return nextStep();

};
