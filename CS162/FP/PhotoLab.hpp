/*********************************************************************

** Program Filename: PhotoLab.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the interface file for
the PhotoLab class, which is a subclass of Room. This file includes
all the class, variable and function declarations.

*********************************************************************/

#ifndef PHOTOLAB_HPP
#define PHOTOLAB_HPP

#include "Room.hpp"

// Defines the interface of the PhotoLab class
class PhotoLab : public Room
{

  public:
    PhotoLab(Player* p1);
    Room* play();

};

#endif
