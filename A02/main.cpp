/*********************************************************************

** Program Filename: main.cpp

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Assignment 2 - Part of a shopping cart program.
This is the main file that runs the program.

*********************************************************************/

#include "List.hpp"

int main() {

  List list1;
  int menuChoice;

  do {
    // instructions
    std::cout << "\nHi there, welcome to the shopping list app." << std::endl;
    std::cout << "Please select one of the following options:\n" << std::endl;
    std::cout << "1. Show your list" << std::endl;
    std::cout << "2. Add items to your list" << std::endl;
    std::cout << "3. Remove items from your list" << std::endl;
    std::cout << "\nEnter 0 to exit the program\n" << std::endl;

    switch (menuChoice = getInt(0,3)) {
      case 1:
        // display the list
        list1.print();
        break;

      case 2:
        // add an item
        list1.addItems();
        break;

      case 3:
        // remove an item
        list1.removeItems();
        break;

      default:
        std::cout << "\nGood bye!\n" << std::endl;
        break;
    }
  } while (menuChoice); // while the menu choice is not zero

  return 0;
};
