/*********************************************************************

** Program Filename: Medusa.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Assignment 3 - Helper function implementations

*********************************************************************/

#include <iostream>
#include <limits> // std::numeric_limits

int getInt(int minSize = std::numeric_limits<int>::min(), int maxSize = std::numeric_limits<int>::max()); // get, validate and return int input
bool getYesNo(); // get and validate yes/no input; returns true (yes) or false (no)
