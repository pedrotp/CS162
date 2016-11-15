/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/15/2016

** Description: Module 6, Assignment 6 -  Part of a geometry program that
handles points and lines in space. This portion creates a point class
that stores coordinates for that point, as well as a method to calculate
the distance between this point and another. This is the implementation
file for the Point class, which defines all the functions the class
contains.

*********************************************************************/

#include "Point.hpp"
#include <cmath> // needed for sqrt and pow in the distanceTo function 

/*********************************************************************

** Description:

** This is the default constuctor that sets the coordinates of the
point to the origin (0,0)

*********************************************************************/

Point::Point()
{
  setXCoord(0.0);
  setYCoord(0.0);
}

/*********************************************************************

** Description:

** This is a constuctor that sets the coordinates to whatever the user
enters as attributes

*********************************************************************/

Point::Point(double xInput, double yInput)
{
  setXCoord(xInput);
  setYCoord(yInput);
}

void Point::setXCoord(double xInput)
{
  xCoord = xInput;
}

void Point::setYCoord(double yInput)
{
  yCoord = yInput;
}

double Point::getXCoord() const
{
  return xCoord;
}

double Point::getYCoord() const
{
  return yCoord;
}

/*********************************************************************

** Description:

** This is a function that takes a second point as a constant reference and
calculates the distance between this point and that one.

*********************************************************************/

double Point::distanceTo(const Point &pointTwo)
{
  return sqrt(pow(getXCoord() - pointTwo.getXCoord(), 2) + pow(getYCoord() - pointTwo.getYCoord(), 2));
}
