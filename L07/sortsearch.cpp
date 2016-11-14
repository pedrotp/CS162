/*********************************************************************

** Program Filename: sortsearch.cpp

** Author: Pedro Torres-Picon

** Date: 11/14/2016

** Description: Lab 7 - A program that showcases various sort and search
functions. This is the implementation file, which includes the source
code for all the functions.

*********************************************************************/

#include "sortsearch.hpp"

/*********************************************************************

** Function: linearSearch()

** Description: a linear search function based on pseudocode found on
page 595 of the Gaddis textbook

** Parameters: an array pointer, the integer size, the integer we are
going to search for

** Pre-Conditions: none

** Post-Conditions: none

** Return: the int index of the search term if found, -1 if not

*********************************************************************/

int linearSearch (int *array, int size, int target) {
  int pos = -1;
  int index = 0;
  while (pos == -1 && index < size) {
    if (array[index] == target) {
      pos = index;
    }
    index++;
  }
  return pos;
};


/*********************************************************************

** Function: bubbleSort()

** Description: a bubble sort function based on pseudocode found on
page 605 of the Gaddis textbook

** Parameters: an array pointer, and an integer that represents the
size of the array

** Pre-Conditions: all values in the array should be integers

** Post-Conditions: none

** Return: nothing

*********************************************************************/

void bubbleSort (int *array, int size) {
  bool swap;
  do {
    swap = false;
    for (int index = 0; index < size - 1; index++) {
      if (array[index] > array[index + 1]) {
        int temp = array[index];
        array[index] = array[index + 1];
        array[index + 1] = temp;
        swap = true;
      }
    }
  } while (swap);
};

/*********************************************************************

** Function: binarySearch()

** Description: a binary search function based on pseudocode found on
page 598 of the Gaddis textbook

** Parameters: an array pointer, the integer size, the integer we are
going to search for

** Pre-Conditions: none

** Post-Conditions: none

** Return: the int index of the search term if found, -1 if not

*********************************************************************/

int binarySearch (int *array, int size, int target) {
  int first = 0;
  int last = size - 1;
  int middle;
  int pos = -1;
  while (pos == -1 && first <= last) {
    middle = (last + first) / 2;
    if (array[middle] == target) {
      pos = middle;
    } else if (array[middle] > target) {
      last = middle - 1;
    } else {
      first = middle + 1;
    }
  }
  return pos;
};

/*********************************************************************

** Description: printArr()

** Takes an array pointer and an integer size for the array, and
prints the array to the screen in a human readable format

** Parameters: a pointer to an array, and the size of the array as an
int value

** Pre-Conditions: none

** Post-Conditions: none

** Return: none

*********************************************************************/

void printArr (int *array, int size) {
  std::cout << "[";
  for (int i = 0; i < size - 1; i++) {
    std::cout << array[i] << ", ";
  }
  if (size > 0) std::cout << array[size - 1];
  std::cout << "]";
};

/*********************************************************************

** Function: getInt()

** Description: Gets and validates integer input from the user, with
the option of entering a valid range for the int. If no minimum or
maximum values are entered, they are set to the min and max allowed
for integers

** Parameters: minSize and maxSize, both ints with defaults

** Pre-Conditions: Show the user instructions and ask them to enter
an integer value

** Post-Conditions: none

** Return: the integer entered by the user

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
