/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 06/27/2016

** Description: Module 2, Assignment 2.c - A program that counts the
number of each type of coin needed to represent a certain number of
cents under a dollar

*********************************************************************/

#include <iostream>
using namespace std;

int main()
{

  int cents, //the amount in cents the user inputs
      q, //number of quarters
      d, //number of dimes
      n, //number of nickels
      p; //number of pennies

  cout << "Please enter an amount in cents less than a dollar." << endl;
  cin >> cents;

  q = cents / 25;
  cents %= 25;
  d = cents / 10;
  cents %= 10;
  n = cents / 5;
  cents %= 5;
  p = cents;

  cout << "Your change will be" << endl;
  cout << "Q: " << q << endl;
  cout << "D: " << d << endl;
  cout << "N: " << n << endl;
  cout << "P: " << p << endl;

  return 0;
}
