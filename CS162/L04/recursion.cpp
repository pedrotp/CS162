/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Lab 4 - This assignment includes 3 functions that
demonstrate recursion. This is the implementation file, which includes
all the source code for the functions.

*********************************************************************/

#include "recursion.hpp"

/*********************************************************************

** Description: reverseString()

** The reverseString function takes a string and prints the reversed
string to the screen using recursion

*********************************************************************/

void reverseString(std::string str) {
  if (str.end() == str.begin()) {
    std::cout << "\n";
  } else {
    std::cout << str.at(str.size() - 1);
    str.erase(str.end() - 1);
    reverseString(str);
  }
};

/*********************************************************************

** Description: sumArray()

** The sumArray function takes an array and an int representing the
size of the array, and returns the sum of all the array elements
using recursion

*********************************************************************/

int sumArray(int* arr, int numElem) {
  if (numElem == 0) {
    return 0;
  } else {
    return arr[numElem - 1] + sumArray(arr,numElem - 1);
  }
};

/*********************************************************************

** Description: triangularNumber()

** The triangularNumber function takes a number and returns the
corresponding triangular number using recursion

*********************************************************************/

int triangularNumber(int num) {
  if (num == 0) {
    return 0;
  } else {
    return num + triangularNumber(num - 1);
  }
};

// HELPER FUNCTIONS

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
}

/*********************************************************************

** Description: printArray()

** Prints an array in a human readable format, with beginning and
ending brackets, and commas/spaces in between

*********************************************************************/

void printArray(int* arr, int size) {
  std::cout << "[";
  for (int i = 0; i < size - 1; i++) {
    std::cout << arr[i] << ", ";
  }
  std::cout << arr[size - 1]<< "]";
}
