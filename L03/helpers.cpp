/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/17/2016

** Description: Lab3 - Helper functions

*********************************************************************/

#include <iostream>

#include "helpers.hpp"

/*********************************************************************

** Description: getInt()

** This function asks the user for an integer value from minSize to
maxSize and validates the input. If it is invalid it askes the user
to enter the number again. Finally, it returns the validated input.

*********************************************************************/

int getInt(int minSize, int maxSize) {
  int userInt;
  bool isValid = false;
  while (!isValid) {
    std::cin >> userInt;
    std::cin.ignore(100,'\n');
    if (userInt >= minSize && userInt <= maxSize) {
      isValid = true;
    } else {
      std::cout << std::endl;
      std::cout << "Invalid input. Please enter an integer between " << minSize << " and " << maxSize << " (inclusive)." << std::endl;
      std::cin.clear();
      std::cin.ignore();
    }
  }
  return userInt;
}

/*********************************************************************

** Description: getYesNo()

** This function asks the user for a char value of y or n, and validates
that input. It then returns the validated input.

*********************************************************************/

bool getYesNo() {
  char input;
  bool yn;
  bool isValid = false;
  while (!isValid) {
    std::cin.get(input);
    std::cout << std::endl;
    if (input == 'Y' || input == 'y') {
      yn = true;
      isValid = true;
    } else if (input == 'N' || input == 'n'){
      yn = false;
      isValid = true;
    } else {
      std::cout << "Invalid input. Please enter y or n only." << std::endl;
      std::cin.clear();
    }
  }
  return yn;
}
