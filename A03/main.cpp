/*********************************************************************

** Program Filename: HarryPotter.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Part of a fantasy dice combat game.
This is the implementation file for the HarryPotter derived class,
which includes the source code for all the functions in the class.

*********************************************************************/

#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"
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
  std::cout << "\nPress 6 for more info, 0 to exit\n" << std::endl;

  switch (getInt(0,6)) {

    case 0:
      cPtr = 0;
      break;

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

** This is the main function that creates a grid and runs the
simulation

*********************************************************************/

int main() {

  bool keepPlaying = true;

  while (keepPlaying) {

    std::cout << "Hi there, welcome to Fantasy Fight Club!" << std::endl;
    std::cout << "Select a character type for player 1:" << std::endl;
    Creature *p1 = newCreature();

    if (p1) { // exit if user chose 0 in player selection menu
      std::cout << "Select a character type for player 2:" << std::endl;
      Creature *p2 = newCreature();

      if (p2) {
        // 50% of the time p1 and p2 are flipped, so whoever goes first is random
        int coinToss = rand() % 100 + 1;

        if (coinToss > 50) {

          Creature *tempPtr = p1;
          p1 = p2;
          p2 = tempPtr;

        }

        bool p1alive = true;
        bool p2alive = true;

        while (p1alive && p2alive) {

          p1alive = p1->defend(p2->attack());
          if (p1alive) {
            p2alive = p2->defend(p1->attack());
          }

        }

        if (p1alive) {
          std::cout << "Player 1 Wins!" << std::endl;
        } else {
          std::cout << "Player 2 Wins!" << std::endl;
        }

        delete p2;

      }

      delete p1;
    }

    std::cout << "Would you like to play again? (y/n)" << std::endl;
    keepPlaying = getYesNo();

  }

  return 0;

};
