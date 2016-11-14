/*********************************************************************

** Program Filename: sortsearch.hpp

** Author: Pedro Torres-Picon

** Date: 11/14/2016

** Description: Lab 7 - A program that showcases various sort and search
functions. This is the interface file, which includes the function
declarations.

*********************************************************************/

#ifndef SORTSEARCH_HPP
#define SORTSEARCH_HPP

#include <iostream>
#include <limits> // std::numeric_limits

int linearSearch (int *array, int size, int target);
void bubbleSort (int *array, int size);
int binarySearch (int *array, int size, int target);

// Helpers:
void printArr (int *array, int size); // print an array to the screen
int getInt(int minSize = std::numeric_limits<int>::min(), int maxSize = std::numeric_limits<int>::max()); // get, validate and return int input

#endif
