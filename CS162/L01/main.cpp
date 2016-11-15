/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 09/29/2016

** Description: Lab 1 - This file has the main program that uses the
readMatrix() and determinant() functions to ask the user for the size
of the matrix, then creates it, asks the user to populate it, prints
it to the screen and finally calculates and prints the determinant. 

*********************************************************************/

#include <iostream>
#include "readMatrix.hpp"
#include "determinant.hpp"

int main() {
  int size; // a variable to hold the size of the matrix input by the user
  // first we ask the user to give us the size of the matrix
  std::cout << "Hi, what size Matrix would you like to work with? (2 or 3)" << std::endl;
  std::cin >> size; // store the value entered in size
  int** arr = new int*[size]; // create a new double pointer that points to an array
  for (int i = 0; i < size; i++) {
    arr[i] = new int[size]; // loop through the arr array and make sure each pointer points to an array too
  }
  // give user confirmation that the matrix has been created
  std::cout << "OK, " << size << "x" << size << " matrix generated." << std::endl;
  readMatrix(&arr, size); // ask user for values to populate the matrix
  // then print the matrix to the screen with a loop
  std::cout << "Great. You have entered the following values:" << std::endl;
  for (int j = 0; j < size; j++) {
    for (int k = 0; k < size; k++) {
      std::cout << arr[j][k];
    }
    std::cout << std::endl;
  }
  // and finally calculate and print the determinant
  std::cout << "The determinant of your matrix is:" << determinant(&arr, size) << std::endl;
  return 0;
}
