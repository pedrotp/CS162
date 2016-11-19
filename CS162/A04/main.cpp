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
    std::cout << "\nYou will build two lineups of creatures that will fight until one of them runs out of players." << std::endl;
    std::cout << "\nHow many creatures should we have in each lineup?" << std::endl;
    int numCreatures = getInt(0);
    std::cout << "\nGreat. Let's go build those two lineups, of " << numCreatures << " creatures each." << std::endl;

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
      std::cout << p1->name() << " added to the lineup!" << std::endl;
      p1->setName("Team " + name1 + " (" + p1->name() + ")");
    }

    // BUILD TEAM 2
    std::cout << "\nOK, now select a name for Team 2:" << std::endl;
    std::string name2;
    std::getline(std::cin,name2);
    std::cout << "\nGreat, now you need to fill Team " << name2 << "'s lineup with " << numCreatures << " creatures" << std::endl;

    for (int i = 1; i <= numCreatures; i++) {
      std::cout << "\nPlease select a type for creature #" << i << ":" << std::endl;
      p2 = newCreature();
      team2.push(p2);
      std::cout << p2->name() << " added to the lineup!" << std::endl;
      p2->setName("Team " + name2 + " (" + p2->name() + ")");
    }

    int score1 = 0;
    int score2 = 0;

    std::cout << "\n******* TOURNAMENT BEGINS *******" << std::endl;

    bool gameOver = false;
    while (!gameOver) {

      p1 = team1.pop();
      p2 = team2.pop();

      if (p1 && p2) {

        std::cout << "\n" << p1->name() << " vs " << p2->name() << ": ";

        bool p1alive = true;
        bool p2alive = true;

        while (p1alive && p2alive) {

          p2alive = p2->defend(p1->attack());
          if (p2alive) {
            p1alive = p1->defend(p2->attack());
          }

        }

        int recovery;

        if (p1alive) {

          std::cout << p1->name() << " wins!";
          if ( (recovery = p1->recover()) ) {
            std::cout << " (strength +" << recovery << ")"; // strength restored
          }
          std::cout << std::endl;
          team1.push(p1);
          score1++;
          losers.push(p2);

        } else {

          std::cout << p2->name() << " wins!";
          if ( (recovery = p2->recover()) ) {
            std::cout << " (strength +" << recovery << ")"; // strength restored
          }
          std::cout << std::endl;
          team2.push(p2);
          score2++;
          losers.push(p1);

        }


      } else if (p2 == 0) {

        // Team 1 is the winner
        gameOver = true;
        std::cout << "\n****** TOURNAMENT WINNERS ******\n" << std::endl;
        std::cout << "  Team " << name1 << std::endl;
        if (p1) delete p1;

      } else if (p1 == 0) {

        // Team 2 is the winner
        gameOver = true;
        std::cout << "\n****** TOURNAMENT WINNERS ******\n" << std::endl;
        std::cout << "  Team " << name2 << std::endl;
        if (p2) delete p2;

      }

    }

    std::cout << "\n******** FINAL SCORES ********\n" << std::endl;
    std::cout << "  Team " << name1 << ": " << score1 << std::endl;
    std::cout << "  Team " << name2 << ": " << score2 << std::endl;
    std::cout << "\n******************************\n" << std::endl;

    // give user the option to see the contents of the loser pile
    std::cout << "Would you like to see the list of losers?" << std::endl;

    if (getYesNo()) {

      std::cout << "\n*********** LOSERS ***********\n" << std::endl;

      while ( (p1 = losers.pop()) ) {

        std::cout << p1->name() << std::endl;
        delete p1;

      }

      std::cout << "\n******************************" << std::endl;

    }

    while ( (p1 = team1.pop()) ) {
      delete p1;
    }

    while ( (p2 = team2.pop()) ) {
      delete p2;
    }

    std::cout << "\nPlay again? (y/n)" << std::endl;
    keepPlaying = getYesNo();

  }

  return 0;

};
