/*********************************************************************

** Program Filename: main.cpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Assignment 4 - Part of a fantasy dice tournament game.
This is the main file that uses all the classes to run the program.

*********************************************************************/

#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "helpers.hpp"

/*********************************************************************

** Description: newCreature()

** This function displays creature options to the user, allows them
to select one, and returns a pointer to an instance of the selected
class

*********************************************************************/

Creature *newCreature() {

  Creature *cPtr;

  std::cout << "\n1: Barbarian" << std::endl;
  std::cout << "2: BlueMen" << std::endl;
  std::cout << "3: Harry Potter" << std::endl;
  std::cout << "4: Medusa" << std::endl;
  std::cout << "5: Vampire" << std::endl;
  std::cout << "\nPress 6 for more info\n" << std::endl;

  switch (getInt(1,6)) {

    case 1:
      cPtr = new Barbarian;
      std::cout << "\nYou chose: Barbarian!\n" << std::endl;
      break;

    case 2:
      cPtr = new BlueMen;
      std::cout << "\nYou chose: Blue Men!\n" << std::endl;
      break;

    case 3:
      cPtr = new HarryPotter;
      std::cout << "\nYou chose: Harry Potter!\n" << std::endl;
      break;

    case 4:
      cPtr = new Medusa;
      std::cout << "\nYou chose: Medusa!\n" << std::endl;
      break;

    case 5:
      cPtr = new Vampire;
      std::cout << "\nYou chose: Vampire!\n" << std::endl;
      break;

    case 6:

      std::cout << "\nBarbarian:" << std::endl;
      std::cout << "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso." << std::endl;
      std::cout << "\nBlueMen:" << std::endl;
      std::cout << "Scrawny lady with snakes for hair. They help with fighting. Just don’t look at her!" << std::endl;
      std::cout << "\nHarry Potter:" << std::endl;
      std::cout << "Why are you reading this? How can you not know who Harry Potter is?" << std::endl;
      std::cout << "\nMedusa:" << std::endl;
      std::cout << "Scrawny lady with snakes for hair. They help with fighting. Just don’t look at her!" << std::endl;
      std::cout << "\nVampire:" << std::endl;
      std::cout << "Suave, debonair, but vicious and surprisingly resilient!\n" << std::endl;

      cPtr = newCreature();
      break;

  }

  return cPtr;

};


/*********************************************************************

** Description: main()

** This is the main function that creates the creatures, gets user
input, and runs the game

*********************************************************************/

int main() {

  srand (std::time(NULL));
  bool keepPlaying = true;
  Queue team1, team2;
  Stack losers;

  while (keepPlaying) {

    std::cout << "\nHi there, welcome to Fantasy Fight Club - Tournament Edition!" << std::endl;
    std::cout << "You will build two lineups of creatures that will fight until one of them runs out of players." << std::endl;
    std::cout << "How many creatures should we have in each lineup?" << std::endl;
    int numCreatures = getInt(0);
    std::cout << "Great. Let's go build those two lineups, of " << numCreatures << " creatures each." << std::endl;

    Creature *p1;
    Creature *p2;

    // BUILD TEAM 1
    std::cout << "\nFirst, select a name for Team 1:" << std::endl;
    std::string name1;
    std::getline(std::cin,name1);
    std::cout << "\nGreat, now you need to fill Team " << name1 << "'s lineup with " << numCreatures << " creatures" << std::endl;

    for (int i = 1; i <= numCreatures; i++) {
      std::cout << "\nPlease select a type for creature #" << i << ":" << std::endl;
      p1 = newCreature();
      team1.push(p1);
      std::cout << p1->type() << " added to the lineup!" << std::endl;
    }

    // BUILD TEAM 2
    std::cout << "\nFirst, select a name for Team 2:" << std::endl;
    std::string name2;
    std::getline(std::cin,name2);
    std::cout << "\nGreat, now you need to fill Team " << name2 << "'s lineup with " << numCreatures << " creatures" << std::endl;

    for (int i = 1; i <= numCreatures; i++) {
      std::cout << "\nPlease select a type for creature #" << i << ":" << std::endl;
      p2 = newCreature();
      team2.push(p2);
      std::cout << p2->type() << " added to the lineup!" << std::endl;
    }

    // 50% of the time p1 and p2 are flipped, so whoever goes first is random
    // int coinToss = rand() % 100 + 1;
    //
    // if (coinToss > 50) {
    //
    //   Creature *tempPtr = p1;
    //   p1 = p2;
    //   p2 = tempPtr;
    //
    // }

    // std::cout << "Team (" << p1->type() << "), will go first.\n" << std::endl;

    int score1 = 0;
    int score2 = 0;

    // while both teams have players
    bool gameOver = false;
    while (!gameOver) {

      p1 = team1.pop();
      p2 = team2.pop();

      if (p1 && p2) {

        std::cout << "\nTeam " << name1 << " (" << p1->type() << ") vs ";
        std::cout << "Team " << name2 << " (" << p2->type() << ")" << std::endl;

        bool p1alive = true;
        bool p2alive = true;

        while (p1alive && p2alive) {

          // std::cout << "Team 1 (" << p1->type() << ") attacked! Player 2 (" << p2->type() << ") has ";
          p2alive = p2->defend(p1->attack());
          if (p2alive) {
            // std::cout << "Player 2 (" << p2->type() << ") attacked! Player 1 (" << p1->type() << ") has ";
            p1alive = p1->defend(p2->attack());
          }

        }

        if (p1alive) {
          std::cout << "Team " << name1 << " (" << p1->type() << ") wins!\n" << std::endl;
          // p1->recover(); // energy restored to x
          team1.push(p1);
          score1++;
          losers.push(p2);
        } else {
          std::cout << "Team " << name2 << " (" << p2->type() << ") wins!\n" << std::endl;
          // p2->recover(); // energy restored to x
          team2.push(p2);
          score2++;
          losers.push(p1);
        }


      } else if (p2 == 0) {
        gameOver = true;
        std::cout << "\nTeam " << name1 << " is the tournament winner!\n" << std::endl;
        // team1 won
      } else if (p1 == 0) {
        gameOver = true;
        std::cout << "\nTeam " << name2 << " is the tournament winner!\n" << std::endl;
        // team2 won
      }

    }

    std::cout << "\n******** FINAL SCORES ********\n" << std::endl;
    std::cout << "Team " << name1 << ": " << score1 << std::endl;
    std::cout << "Team " << name1 << ": " << score1 << std::endl;
    std::cout << "\n******************************\n" << std::endl;

    // give user the option to see the contents of the loser pile
    std::cout << "Would you like to see the list of losers?" << std::endl;
    if (getYesNo()) {
      while (p1 = losers.pop()) {
        std::cout << "Team " << name << " (" << p1->type() << ")" << std::endl;
        delete p1;
      }
    }

    // delete everything
    while (p1 = losers.pop()) {
      delete p1;
    }

    while (p1 = team1.pop()) {
      delete p1;
    }

    while (p1 = team2.pop()) {
      delete p1;
    }

    std::cout << "\nPlay again? (y/n)" << std::endl;
    keepPlaying = getYesNo();

  }

  return 0;

};


/********************** FOR TESTING ONLY *****************************
*** UNCOMMENT THIS AND COMMENT THE OTHER MAIN METHOD ABOVE TO TEST ***
**********************************************************************

** Description: main() [TEST]

** This is a test version of the main function that runs a thousand
simulations of fights between two hard coded characters

*********************************************************************/

// int main() {
//
//   srand (std::time(NULL));
//
//   int p1wins = 0;
//   int p2wins = 0;
//
//   for (int i = 0; i < 10000; i++) {
//
//     Creature *p1 = new /* Creature Type */;
//     Creature *p2 = new /* Creature Type */;
//
//     bool p1alive = true;
//     bool p2alive = true;
//
//     while (p1alive && p2alive) {
//
//       std::cout << "Player 1 (" << p1->type() << ") attacked! Player 2 (" << p2->type() << ") has ";
//       p2alive = p2->defend(p1->attack());
//       if (p2alive) {
//         std::cout << "Player 2 (" << p2->type() << ") attacked! Player 1 (" << p1->type() << ") has ";
//         p1alive = p1->defend(p2->attack());
//       }
//
//     }
//
//     if (p1alive) {
//       p1wins++;
//       std::cout << "\nPlayer 1 (" << p1->type() << ") wins!" << std::endl;
//     } else {
//       p2wins++;
//       std::cout << "\nPlayer 2 (" << p2->type() << ") wins!" << std::endl;
//     }
//
//     delete p1;
//     delete p2;
//
//     // added a delay so the seed for rand would be different between steps
//     // std::cout.flush();
//     // usleep(1500000);
//
//     // added a user controlled delay for the same issue
//     // std::cout << "Press any key to continue..." << std::endl;
//     // std::cin.get();
//
//   }
//
//   std::cout << "P1 won " << p1wins << " times." << std::endl;
//   std::cout << "P2 won " << p2wins << " times." << std::endl;
//   return 0;
//
// };
