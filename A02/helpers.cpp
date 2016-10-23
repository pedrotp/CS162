/*********************************************************************

** Program Filename: helpers.cpp

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: This is the implementation file for the helper functions.

*********************************************************************/

#include "helpers.hpp"

/*********************************************************************

** Description: getFloat()

** Gets and validates string input from the user, with the option of
entering a valid range for the float. If no minimum or maximum values
are entered, they are set to the min and max allowed for float variables

*********************************************************************/

float getFloat(float minSize, float maxSize) {
  float userFloat;
  bool isValid = false;
  while (!isValid) {
    if (std::cin >> userFloat && userFloat >= minSize && userFloat <= maxSize) {
      isValid = true;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } else {
      // std::cout << std::endl;
      std::cout << "Invalid input. Please enter an real number between " << minSize << " and " << maxSize << " (inclusive)." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }
  return userFloat;
};

/*********************************************************************

** Description: getInt()

** Gets and validates string input from the user, with the option of
entering a valid range for the int. If no minimum or maximum values
are entered, they are set to the min and max allowed for int variables

*********************************************************************/

int getInt(int minSize, int maxSize) {
  int userInt;
  bool isValid = false;
  while (!isValid) {
    if (std::cin >> userInt && userInt >= minSize && userInt <= maxSize) {
      isValid = true;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } else {
      // std::cout << std::endl;
      std::cout << "Invalid input. Please enter an integer between " << minSize << " and " << maxSize << " (inclusive)." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }
  return userInt;
};
