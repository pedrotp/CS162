/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/15/2016

** Description: Module 6, Assignment 6 -  Part of a geometry program that
handles points and lines in space. This portion creates a point class
that stores coordinates for that point, as well as a method to calculate
the distance between this point and another. This is the interface file
for the Point class, which includes the class, variable and function
declarations.

*********************************************************************/

#ifndef POINT_HPP
#define POINT_HPP

// Defines the interface of the Point class
class Point
{
  private:
    double xCoord, yCoord;

  public:
    Point();
    Point(double, double);
    void setXCoord(double);
    void setYCoord(double);
    double getXCoord() const;
    double getYCoord() const;
    double distanceTo(const Point&);
};
#endif
