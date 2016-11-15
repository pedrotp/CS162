/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/15/2016

** Description: Module 6, Assignment 6 -  Part of a geometry program that
handles points and lines in space. This portion creates a LineSegment
class that has information about a particular line created from two points.
This is the implementation file for the LineSegment class, which defines
all the functions the class contains.

*********************************************************************/

#include "LineSegment.hpp"

/*********************************************************************

** Description:

** This is the default constructor that creates two default points (0,0)
and (1,1) and sets them as the endpoints for the line segment

*********************************************************************/

LineSegment::LineSegment()
{
  Point def1; // set to (0,0) by default
  Point def2(1,1);
  setEnd1(def1);
  setEnd2(def2);
}

/*********************************************************************

** Description:

** This is a constuctor that sets the endpoints to two points provided
by the user as attributes

*********************************************************************/

LineSegment::LineSegment(Point p1, Point p2)
{
  setEnd1(p1);
  setEnd2(p2);
}

void LineSegment::setEnd1(Point endIn)
{
  end1 = endIn;
}

void LineSegment::setEnd2(Point endIn)
{
  end2 = endIn;
}

Point LineSegment::getEnd1()
{
  return end1;
}

Point LineSegment::getEnd2()
{
  return end1;
}

/*********************************************************************

** Description:

** This is a function that calculates the length of the line segment
by using the distanceTo method of one of the points, with the other
point as an argument

*********************************************************************/

double LineSegment::length()
{
  return end1.distanceTo(end2);
}

/*********************************************************************

** Description:

** This is a function that uses the y and x coordinates from both
endpoints to calculate and return the slope of the line segment

*********************************************************************/

double LineSegment::slope()
{
  return (end2.getYCoord() - end1.getYCoord())/(end2.getXCoord() - end1.getXCoord());
}
