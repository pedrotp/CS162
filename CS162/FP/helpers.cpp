/*********************************************************************

** Program Filename: Helpers.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Helper function interface file

*********************************************************************/

#include "helpers.hpp"

/*********************************************************************

** Description: getInt()

** Gets and validates integer input from the user, with the option of
entering a valid range for the int. If no minimum or maximum values
are entered, they are set to the min and max allowed for integers

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

** Description: getYesNo()

** Gets and validates yes or no input from the user, and returns
true if the user selects yes, and false if the user selects no

*********************************************************************/

bool getYesNo() {
  char yn;
  bool isValid = false;
  while (!isValid) {
    std::cin >> yn;
    if (yn == 'Y' || yn == 'y') {
      yn = 'y';
      isValid = true;
    } else if (yn == 'N' || yn == 'n'){
      yn = 'n';
      isValid = true;
    } else {
      std::cout << "Invalid input. Please enter y or n only." << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  }
  return !!(yn == 'y');
};

/*********************************************************************

** Description: getChar()

** Gets, validates and returns char input from the user

*********************************************************************/

char getChar() {
  std::string in;
  char ch;
  bool isValid = false;
  while (!isValid) {
    std::getline(std::cin, in);
    if (in.size() == 1) {
      ch = in.at(0);
      isValid = true;
    } else {
      std::cout << "Invalid input. Please a single character." << std::endl;
    }
  }
  return ch;
};
