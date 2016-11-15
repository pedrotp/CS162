/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Lab 4 - This assignment includes 3 functions that
demonstrate recursion. This is the interface file, which includes the
function declarations.

*********************************************************************/

#include <string>
#include <iostream>
#include <limits> // std::numeric_limits

#ifndef RECURSION_HPP
#define RECURSION_HPP

void reverseString(std::string str);
int sumArray(int* arr, int numElements);
int triangularNumber(int num);
int getInt(int minSize = std::numeric_limits<int>::min(), int maxSize = std::numeric_limits<int>::max()); // helper function to validate int input
void printArray(int* arr, int size); // helper function to print an array

#endif
