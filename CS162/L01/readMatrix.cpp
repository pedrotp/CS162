/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 09/29/2016

** Description: Lab 1 - This is the implementation file for the readMatrix()
function, which includes the source code for the function itself

*********************************************************************/

#include "readMatrix.hpp"
#include <iostream> // std::cout & std::cin

void readMatrix(int * **arrPtr, int size) {
  int inputVal; // variable to hold each input
  int** arr = *arrPtr; // dereference the pointer for simplicity
  for (int i = 0; i < size; i++) { // loop through every value in the matrix and ask for a value every time
    for (int j = 0; j < size; j++) {
      std::cout << "Please enter position " << j << " for row " << i << ":" << std::endl;
      std::cin >> inputVal;
      arr[i][j] = inputVal;
    }
  }
}
