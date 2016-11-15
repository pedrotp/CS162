/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/15/2016

** Description: Module 6, Assignment 6 -  Test file

*********************************************************************/

#include "LineSegment.hpp"
#include <iostream>

using namespace std;

int main()
{
  Point p1(-1.5, 0.0);
  Point p2(1.5, 4.0);
  double dist = p1.distanceTo(p2);
  cout << "The distance between (" << p1.getXCoord() << "," << p1.getYCoord() << ") and (" << p2.getXCoord() << "," << p2.getYCoord() << ") is " << dist << endl;

  Point p3(4.3, 7.52);
  Point p4(-17.0, 1.5);
  LineSegment ls1(p3, p4);
  double length = ls1.length();
  double slope = ls1.slope();
  cout << "The length of the line is " << length << ", and the slope is " << slope;

  return 0;
}
