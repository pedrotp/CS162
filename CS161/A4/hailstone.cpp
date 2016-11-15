/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/08/2016

** Description: Assignment 4.c - This program creates a 'hailstone'
function that takes a positive integer and generates a sequence based on the
following rule: if the number is even, divide it by 2, and if it is odd
multiply it by 3 and add 1. This program returns the number of steps it takes
until the sequence generates the number 1.

*********************************************************************/

#include <iostream>
using namespace std;

int hailstone(int num) {
  int count = 0; // start the counter at 0
  while (num > 1) { // the loop keeps going as long as the number is a positive integer but not 1
    if (num % 2 == 0) {
      num /= 2; // if the number is even, it is divided by 2
    } else {
      num = num * 3 + 1; // if the number is odd, it is multiplied by 3 and then 1 added to that
    }
    // cout << num << endl;
    count++; // increment the counter at every iteration of the loop
  }
  // cout << "Count: " << count << endl;
  return count; // return the final count
}

/*
int main() {
  int start;
  cout << "Enter a number to begin." << endl;
  cin >> start;
  hailstone(start);
  return 0;
}
*/
