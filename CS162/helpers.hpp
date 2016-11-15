
#include <iostream>
#include <limits> // std::numeric_limits

int getInt(int minSize = std::numeric_limits<int>::min(), int maxSize = std::numeric_limits<int>::max()); // get, validate and return int input
bool getYesNo(); // get and validate yes/no input; returns true (yes) or false (no)
void printArr (int *array, int size); // prints an array to the screen
