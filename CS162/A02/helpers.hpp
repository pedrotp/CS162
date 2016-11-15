/*********************************************************************

** Program Filename: helpers.hpp

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: This is the interface file for the helper functions.

*********************************************************************/

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <limits> // std::numeric_limits

  float getFloat(float minSize = std::numeric_limits<float>::min(), float maxSize = std::numeric_limits<float>::max()); // helper function to validate float input
  int getInt(int minSize = std::numeric_limits<int>::min(), int maxSize = std::numeric_limits<int>::max()); // helper function to validate int input

#endif
