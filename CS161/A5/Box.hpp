/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/13/2016

** Description: Module 5, Assignment 5.a - Part of a program that
computes the volume and surface area of a box given the height, width,
and length. This is the interface file that includes the class
declaration variable declarations, and function declarations for
constructors and getters/setters.

*********************************************************************/

#ifndef BOX_HPP
#define BOX_HPP

// Defines the interface of the Box class
class Box
{
  private:
    double height, width, length;

  public:
    Box();
    Box(double, double, double);
    bool setHeight(double);
    bool setWidth(double);
    bool setLength(double);
    double getVolume();
    double getSurfaceArea();
};
#endif
