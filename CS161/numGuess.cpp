/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/03/2016

** Description: Assignment 3.c - A guessing game! The user enters a
secret number, and then someone else proceeds to guess that number while
receiving hints from the program.

*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
  int target, guesses = 0, current;

  cout << "Enter an integer for the player to guess." << endl;
  cin >> target;

  cout << "Enter your guess." << endl;
  do {
    cin >> current;
    guesses++;
    if (current > target) cout << "Too high - try again." << endl;
    if (current < target) cout << "Too low - try again." << endl;
  } while (current != target);

  cout << "You guessed it in " << guesses << " tries." << endl;

  return 0;
}
