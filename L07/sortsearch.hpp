
#ifndef SORTSEARCH_HPP
#define SORTSEARCH_HPP

#include <iostream>
#include <ctime> // std::time
#include <limits> // std::numeric_limits

int linearSearch (int *array, int size, int target);
void bubbleSort (int *array, int size);
int binarySearch (int *array, int size, int target);
void printArr (int *array, int size);
int getInt(int minSize = std::numeric_limits<int>::min(), int maxSize = std::numeric_limits<int>::max()); // get, validate and return int input

#endif
