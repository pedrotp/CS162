/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/20/2016

** Description: Module 7, Assignment 7 - This file contains just one
function called findMode that takes an array and its size, and returns
a vector containing the mode or modes, which are the items that repeat
the most within the elements of the array.

*********************************************************************/

#include <vector>
#include <algorithm>

using namespace std;

// this function returns a vector of integers, and takes an array and its size
vector<int> findMode(int array[], int size)
{
  vector<int> result;
  int count = 0, max = 0;

  // first, we sort the array so all the similar values are side by side
  sort(array, array + size);

  // then, we iterate through the sorted array to count the modes
  for (int index = 0; index < size; index++)
  {
    // the counter is increased at every step
    count++;
    // but if we are at the end of the array or at the end of a block of equal
    // values, then we set it back to zero and check whether the count is
    // equal or greater to the max count
    if (index == size - 1 || array[index] != array[index + 1])
    {
      // if the count is larger than the max, then we clear the result vector,
      //push the new mode to the vector and set the count as the new max
      if (count > max)
      {
        max = count;
        result.clear();
        result.push_back(array[index]);
      }
      // if the count is equal to the max, then we just add the value to the
      // result vector because it is another mode
      else if (count == max)
      {
        result.push_back(array[index]);
      }
      count = 0;
    }
  }
  return result;
}
