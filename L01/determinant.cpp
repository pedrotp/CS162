/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 09/29/2016

** Description: Lab 1 - This is the implementation file for the determinant()
function, which includes the source code for the function itself

*********************************************************************/

#include "determinant.hpp"

int determinant(int * **arrPtr, int size) {
  int result; // result value to be returned
  int** arr = *arrPtr; // dereference the pointer for simplicity
  // below we check whether it is a 2x2 or 3x3 matrix and hard code the
  // formulas to get the determinants
  if (size == 2) {
    result = arr[0][0] * arr[1][1] - arr[0][1] * arr[1][0];
  } else if (size == 3) {
    result = arr[0][0] * (arr[1][1] * arr[2][2] - arr[1][2] * arr[2][1])
             - arr[0][1] * (arr[1][0] * arr[2][2] - arr[1][2] * arr[2][0])
             + arr[0][2] * (arr[1][0] * arr[2][1] - arr[1][1] * arr[2][0]);
  }
  return result;
}
