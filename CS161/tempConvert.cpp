/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 06/27/2016

** Description: Module 2, Assignment 2.b - A program that converts
Celsius temperatures to Fahrenheit

*********************************************************************/

#include <iostream>
using namespace std;

int main()
{
  double ctemp, ftemp;

  cout << "Please enter a Celsius temperature." << endl;
  cin >> ctemp;

  ftemp = 9 * ctemp / 5 + 32;

  cout << "The equivalent Fahrenheit temperature is:" << endl;
  cout << ftemp << endl;

  return 0;
}
