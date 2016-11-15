/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/13/2016

** Description: Module 5, Assignment 5.a - Test file

*********************************************************************/

#include "Box.hpp"
#include <iostream>

using namespace std;

int main()
{

  double height, width, length;

  cout << "Enter height, width and length" << endl;
  cin >> height;
  cin >> width;
  cin >> length;

  Box myBox(height, width, length);

  cout << "The surface area is " << myBox.getSurfaceArea() << endl;
  cout << "The volume is " << myBox.getVolume() << endl;
  
  return 0;
}
