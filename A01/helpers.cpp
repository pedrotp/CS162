/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/07/2016

** Description: Activity 1 - Part of an implementation of Langton's
Ant. This is the "helpers" implementation file that includes all the
source code for the helper function for this program.

*********************************************************************/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "helpers.hpp"

/*********************************************************************

** Description: getMatrixSize()

** This function asks the user for a number to be used to set the size
of the matrix where the Ant will move around. The function then thanks
the user and returns this number. This function does not actually
create the matrix.

*********************************************************************/

int getMatrixSize() {
  std::cout << "How large would you like the board to be?" << std::endl;
  std::cout << "i.e. enter 100 for a 100x100 matrix (integers only please)" << std::endl;
  std::cout << "tip: make sure it is large enough for the ant to move around" << std::endl;
  int size = getInt(1); // get a positive integer
  std::cout << "Great! We will generate a " << size << "x" << size << " board for our ant to play in." << std::endl;
  std::cout << std::endl;
  return size;
}

/*********************************************************************

** Description: getNumMoves()

** This function asks the user for a number to be used to set the max
number of moves the Ant will make before stopping. The function then
thanks the user and returns this number. This function does not actually
set the number as the max.

*********************************************************************/

int getNumMoves() {
  std::cout << "How many moves would you like the ant to make? (enter an integer value)" << std::endl;
  std::cout << "tip: things start to get mildly interesting above 100 moves, and REALLY interesting above 10,000 moves" << std::endl;
  int moves = getInt(1); // get a positive integer
  std::cout << "Awesome. Our ant will move " << moves << " times." << std::endl;
  std::cout << std::endl;
  return moves;
}

/*********************************************************************

** Description: getStartCoords()

** This function first asks the user to choose between randomly
generating the starting coordinates or specifying them directly. If the
user selects random numbers, they are generated and put into variables
that were passed in as pointers. If the user wants to define the starting
position, then they are asked for two numbers and those are put into
the variables that were passed to the function as pointers.

*********************************************************************/

void getStartCoords(int* xPtr, int* yPtr, int matrixSize) {
  std::cout << "Please enter the number 1 if you want the ant to start at a random position, or the number 2 if you want to pick a specific starting position." << std::endl;
  switch (getInt(1,2)) {
    case 1:
    // select two random numbers between 0 and matrixSize - 1 and assign them to xPtr and yPtr
      srand (std::time(NULL));
      *xPtr = rand() % matrixSize;
      *yPtr = rand() % matrixSize;
      break;
    case 2:
      // ask the user for two numbers between 0 and matrixSize - 1 and assign them to xPtr and yPtr
      std::cout << "Please enter the x coordinate of the starting position:" << std::endl;
      *xPtr = getInt(0, matrixSize - 1);
      std::cout << "Please enter the y coordinate of the starting position:" << std::endl;
      *yPtr = getInt(0, matrixSize - 1);;
      break;
  }
  std::cout << "OK, the ant will start at position (" << *xPtr << "," << *yPtr << ")" << std::endl;
}

/*********************************************************************

** Description: createMatrix()

** This function creates and returns a 2D matrix of the size specified
by the argument. i.e. if 2 is entered, the function would return a 2x2 matrix

*********************************************************************/

int** createMatrix(int size) {
  int** matrix = new int*[size]; // create a new double pointer that points to an array
  for (int i = 0; i < size; i++) {
    matrix[i] = new int[size]; // loop through the matrix array and make sure each pointer points to an array of ints
  }
  return matrix;
}

/*********************************************************************

** Description: clearScreen()

** This function clears the screen by entering ANSI escape codes that
insert whitespace and position the cursor at the top left corner

*********************************************************************/

void clearScreen() {
  std::cout << "\033[2J\033[1;1H";
}

/*********************************************************************

** Description: displayBoard()

** This function uses a loop to display a 2x2 matrix. The switch statement
replaces the numbers 0, 1 and 2 (which is how each different position is
represented in the 2D array) into whatever characters we want to show the
user to represent white/black/ant

*********************************************************************/

void displayBoard(int** board, int size) {
  for (int j = 0; j < size; j++) {
    for (int k = 0; k < size; k++) {
      switch (board[j][k]) {
        case 0:
          std::cout << " ";
          break;
        case 1:
          std::cout << "#";
          break;
        case 2:
          std::cout << "*";
          break;
      }
    }
    std::cout << std::endl;
  }
}

/*********************************************************************

** Description: deallocate()

** This function deallocates the memory that was allocated with the "new"
keyword in createMatrix()

*********************************************************************/

void deallocate(int** board, int size) {
  for (int i = 0; i < size; i++) {
    delete [] board[i]; // loop through the matrix array and deallocate each array pointer
  }
  delete [] board;
}

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
    if (userInt >= minSize && userInt <= maxSize) {
      isValid = true;
    } else {
      std::cout << "Invalid input. Please enter an integer between " << minSize << " and " << maxSize << " (inclusive)." << std::endl;
      std::cin.clear();
      std::cin.ignore(10000,'\n');
    }
  }
  return userInt;
}

/*********************************************************************

** Description: getYesNo()

** This function asks the user for a char value of y or n, and validates
that input. It then returns the validated input.

*********************************************************************/

char getYesNo() {
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
  }
  return yn;
}

/* GENERIC MENU FUNCTION TO BE REUSED IN FUTURE PROJECTS
  (U) */

/*********************************************************************

** Description: genMenu()

** This is a generic menu function to be reused in future projects. It
uses the getInt function above to get an integer from minValue
to maxValue, which are the starting and ending menu options.

*********************************************************************/

void genMenu(int minValue, int maxValue) {
  switch (getInt(minValue,maxValue)) {
    case 1:
      // write code for menu option 1
      break;
    case 2:
      // write code for menu option 2
      break;
    // continue adding case statements for every menu option possible
    default:
      break;
    // remember to assing an option to "exit" the program!
  }
}
