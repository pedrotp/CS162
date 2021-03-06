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

/*********************************************************************

** Description: WrittenTest()

** This is the constructor for the WrittenTest class, which
passes the p variable to the constructor for the Room abstract
base class

*********************************************************************/

WrittenTest::WrittenTest(Player* p1) : Room(p1){
};

/*********************************************************************

** Description: play()

** This function runs the WrittenTest mini-game, which runs a mock
"test" and generates a random grade between 75 and 100

*********************************************************************/

Room* WrittenTest::play() {

  std::cout << "Current room: Written Test Room\n\n" << std::endl;

  if (!checkInv("wtest_results") && !checkInv("form_409h")) {

    if (checkInv("form_57b")) {

      bool correct = true;
      std::cout << "Welcome, please take a seat. The test is about to begin.\n" << std::endl;
      usleep(1000000);
      std::cout << "[Written Test in progress...]" << std::endl;
      usleep(3000000);
      int score = rand() % 26 + 75; // score is randomly generated between 75 and 100
      p->currentTime += 10; // time is incremented for completing the activity
      if (score >= 80) {

        std::cout << "You passed! You have the knowledge and are ready to hit the road. Here are your test results." << '\n';
        if (p->inventory.size() < 4) p->inventory.insert("wtest_results");
        std::cout << "\n[wtest_results added to inventory]\n" << std::endl;

      } else {

        std::cout << "Hm, your score was " << score << ", just shy of 80. Study up and come back to take the test again!" << std::endl;

      }

    } else {

      std::cout << "Sorry! You can't take the Written Test without Form 57B (Proof of ID). I wouldn't know who you are!\n";
      std::cout << "Please come back when you have the proper forms. You can get them in the Forms Department.\n" << std::endl;

    }

  } else {

    std::cout << "Hm, looks like you've already passed your Written Test. You're done here!" << std::endl;

  }

  return nextStep();

};
