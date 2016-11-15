/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/03/2016

** Description: Assignment 3.a - A program that asks the user how many
integers they want to enter, prompt the user to enter that many integers,
and finally display the largest and smallest of those numbers.

*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
  int numint, max, min, input;

  // create a do while loop to make sure the integer entered is >0
  do {
    cout << "How many integers would you like to enter?" << endl;
    cin >> numint;
  } while (numint < 1);

  // once we have a number we ask the user to enter that number of integers
  cout << "Please enter " << numint << " integers." << endl;

  // after they've entered the first number, it is set as the maximum and minimum
  cin >> min;
  max = min;
  numint--; // decrease the counter because we already have one integer

  // create a loop to ask the user for as many more numbers as needed
  while (numint > 0) {
    cin >> input;
    // in every loop, check if the number entered is the new max or min
    if (input > max) max = input;
    if (input < min) min = input;
    numint--; // decrease the counter to avoid an infinite loop
  }

  cout << "min: " << min << endl;
  cout << "max: " << max << endl;

  return 0;
}
