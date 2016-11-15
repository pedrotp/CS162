/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/08/2016

** Description: Assignment 4.a - A program that takes the time an
object has been falling (in seconds), and returns the distance the
object has fallen (in meters).

*********************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

const double GRAVITY_CONSTANT = 9.8;

double fallDistance(double fallTime)
{
  return GRAVITY_CONSTANT * pow(fallTime,2.0) / 2;
}

/*
int main()
{
  cout << fallDistance(3.0) << endl;
  return 0;
}
*/
