/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/13/2016

** Description: Module 5, Assignment 5.a - Part of a program that
computes the volume and surface area of a box given the height, width,
and length. This is the implementation file that defines all the
functions the class contains.

*********************************************************************/

#include "Box.hpp"

bool Box::setHeight(double hgt)
{
  bool valid = true;

  if (hgt >= 0)
    height = hgt;
  else
    valid = false;

  return valid;
}

bool Box::setWidth(double wdt)
{
  bool valid = true;

  if (wdt >= 0)
    width = wdt;
  else
    valid = false;

  return valid;
}

bool Box::setLength(double lgt)
{
  bool valid = true;

  if (lgt >= 0)
    length = lgt;
  else
    valid = false;

  return valid;
}

double Box::getVolume()
{
  double volume = width * length * height;

  return volume;
}

double Box::getSurfaceArea()
{
  double area = 2 * length * width + 2 * length * height + 2 * height * width;

  return area;
}

/*********************************************************************

** Description:

** a default constructor that sets all values to 1

*********************************************************************/
//

Box::Box()
{
  setHeight(1);
  setWidth(1);
  setLength(1);
}

/*********************************************************************

** Description:

** constructor that sets the values to provided doubles

*********************************************************************/

Box::Box(double hgt, double wdt, double lgt) {
  setHeight(hgt);
  setWidth(wdt);
  setLength(lgt);
}
