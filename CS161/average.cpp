/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 06/27/2016

** Description: Module 2, Assignment 2.a - A program that calclulates
the average from 5 numbers given by the user

*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
  // declare 5 variables for the numbers and one for the average
  double num1, num2, num3, num4, num5, avg;

  cout << "Please enter five numbers." << endl;
  cin >> num1;
  cin >> num2;
  cin >> num3;
  cin >> num4;
  cin >> num5;

  // compute the average
  avg = (num1 + num2 + num3 + num4 + num5) / 5;

  cout << "The average of those numbers is:" << endl;
  cout << avg << endl;

  return 0;
}
