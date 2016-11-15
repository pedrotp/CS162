/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/15/2016

** Description: Module 6, Assignment 6 -  Part of a geometry program that
handles points and lines in space. This portion creates a LineSegment
class that has information about a particular line created from two points.
This is the interface file for the LineSegment class, that includes the
class, variable and function declarations.

*********************************************************************/

#ifndef LINESEGMENT_HPP
#define LINESEGMENT_HPP

#include "Point.hpp"

// Defines the interface of the LineSegment class
class LineSegment
{
  private:
    Point end1, end2;

  public:
    LineSegment();
    LineSegment(Point, Point);
    void setEnd1(Point);
    void setEnd2(Point);
    Point getEnd1();
    Point getEnd2();
    double length();
    double slope();
};
#endif
