/*********************************************************************

** Program Filename: main.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Lab 6 - A program that showcases Stack and Queue data
structures. This is the main file that uses all the classes to run
the program.

*********************************************************************/

#include <string>
#include <limits>
#include "Stack.hpp"
#include "Queue.hpp"

/*********************************************************************

** Description: getInt()

** Gets and validates integer input from the user, in a specified
range between minSize and maxSize inclusive

*********************************************************************/

int getInt(int minSize, int maxSize) {

  int userInt;
  bool isValid = false;

  while (!isValid) {
    if (std::cin >> userInt && userInt >= minSize && userInt <= maxSize) {
      isValid = true;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } else {
      std::cout << "Invalid input. Please enter an integer between " << minSize << " and " << maxSize << " (inclusive)." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }

  return userInt;

};

/*********************************************************************

** Description: showHelp()

** Prints a set of instructions that explains to the user how to run
the program

*********************************************************************/

void showHelp(std::string listType) {

  std::cout << "\n* To add something to your " << listType << ", enter the command 'push'" << std::endl;
  std::cout << "* To remove something from your " << listType << ", enter the command 'pop'" << std::endl;
  std::cout << "* To see these instructions again, type 'help'" << std::endl;
  std::cout << "* To exit, type 'exit'\n" << std::endl;
  std::cout << "NOTE: If you try to pop from an empty " << listType << ", you will see an error message\nfollowed by a message saying the number -1 has been removed. Ignore this.\nThe number -1 was not removed from the empty " << listType << ".\n" << std::endl;

}

/*********************************************************************

** Description: main()

** This is the main function that runs the program to demonstrate the
use of the Stack and Queue classes

*********************************************************************/

int main() {

  std::cout << "\nHey there, welcome to the Stack/Queue demo!" << std::endl;
  std::cout << "Please choose what data structure to work with:\n" << std::endl;
  std::cout << "1: Stack" << std::endl;
  std::cout << "2: Queue" << std::endl;
  std::cout << "\n(Press 0 to exit)\n" << std::endl;

  List *myList; // to store the selected data structure
  std::string listType; // stores the type of structure selected

  int choice = getInt(0,2);

  if (!choice) { // if user choses zero, exit

    std::cout << "\nGood bye!\n" << std::endl;

  } else if (choice == 1) { // if user chooses 1, initialize myList to a Stack
    myList = new Stack;
    listType = "Stack";
  } else if (choice == 2) { // if user chooses 2, initialize myList to a Queue
    myList = new Queue;
    listType = "Queue";
  }

  if (choice) {

    std::cout << "\nGreat! Here are some commands to work with your " << listType << ":" << std::endl;

    showHelp(listType); //

    std::string command; // to store the user's commands
    int num; // to store the number entered by the user to push

    while (command != "exit") {

      std::getline(std::cin, command);

      if (command == "push") {

        std::cout << "\nEnter a number to push: ";

        std::cin >> num;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');

        myList->push(num);
        std::cout << "\n" << num << " has been added to the " << listType << "\n" << std::endl;

      } else if (command == "pop") {

        std::cout << "\n" << myList->pop() << " has been removed from the " << listType << "\n" << std::endl;

      } else if (command == "help") {

        showHelp(listType);

      } else if (command == "exit") {

        std::cout << "\nGood bye!\n" << std::endl;

      } else {

        std::cout << "\nWhoops! You entered an invalid command" << std::endl;
        std::cout << "Please enter *only* the words 'push', 'pop', 'help' or 'exit' in all lowercase\n" << std::endl;

      }

    }

  }

  return 0;

};
