/*********************************************************************

** Program Filename: main.cpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Lab 8 - A program that showcases an implementation of
a Queue data structure using a doubly-linked circular structure. This
is the main file that uses the Queue class and helper functions to
run the program and test the functionality.

*********************************************************************/

#include <string>
#include <limits>

#include "Queue.hpp"

/*********************************************************************

** Description: getInt()

** Gets and validates integer input from the user, with the option of
entering a valid range for the int. If no minimum or maximum values
are entered, they are set to the min and max allowed for integers

*********************************************************************/

int getInt(int minSize = std::numeric_limits<int>::min(), int maxSize = std::numeric_limits<int>::max()) {

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

** Description: main()

** This is the driver function that runs the program, takes user input,
and shows user output to test the functionality of the queue

*********************************************************************/

int main () {

  Queue myQueue;
  std::cout << "\nHey there! Welcome to the Circular Queue program\n" << std::endl;

  bool exitFlag = false;
  while (!exitFlag) {

    std::cout << "Please select one of the following choices:" << std::endl;
    std::cout << "\na. Add a value to the queue" << std::endl;
    std::cout << "b. Display first node (front) value" << std::endl;
    std::cout << "c. Remove first node (front) value" << std::endl;
    std::cout << "d. Display the queue contents" << std::endl;
    std::cout << "x. Exit\n" << std::endl;

    std::string input;
    char choice;

    std::getline(std::cin, input);

    if (input.length() == 1) {
      choice = input[0];
    } else {
      choice = 'e';
    }

    int val;

    switch (choice) {

      case 'a':
      case 'A':
        std::cout << "Enter value to add: ";
        val = getInt(0);
        myQueue.addBack(val);
        std::cout << "\nA node with value " << val << " was added to the queue\n" << std::endl;
        break;

      case 'b':
      case 'B':
        val = myQueue.getFront();
        if (val == -1) {
          std::cout << "\nError! The queue is empty.\n" << std::endl;
        } else {
          std::cout << "\nThe value of the node at the front of the queue is " << val << "\n" << std::endl;
        }
        break;

      case 'c':
      case 'C':
        val = myQueue.removeFront();
        if (val == -1) {
          std::cout << "\nError! The queue is already empty, nothing to remove\n" << std::endl;
        } else {
          std::cout << "\nA node with a value of " << val << " was removed from the front of the queue\n" << std::endl;
        }
        break;

      case 'd':
      case 'D':
        std::cout << std::endl;
        if (myQueue.displayContents() == -1) {
            std::cout << "Error: The queue is empty, nothing to display\n";
        }
        std::cout << std::endl;
        break;

      case 'x':
      case 'X':
        std::cout << "Good bye!" << '\n';
        exitFlag = true;
        break;

      default:
        std::cout << "\nWhoops! Invalid entry, please enter one of the menu choices.\n" << std::endl;
        break;

    }

  }

  return 0;

};
