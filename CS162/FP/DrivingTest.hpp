/*********************************************************************

** Program Filename: DrivingTest.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the interface file for
the DrivingTest class, which is a subclass of Room. This file includes
all the class, variable and function declarations.

*********************************************************************/

#ifndef DRIVINGTEST_HPP
#define DRIVINGTEST_HPP

#include "Room.hpp"

// Defines the interface of the DrivingTest class
class DrivingTest : public Room
{

  private:
    int xCoord; // the car's x coordinate in the track
    int yCoord; // the car's y coordinate in the track

  public:
    DrivingTest(Player* p1);
    Room* play();
    void displayTrack(int track[15][25]);

};

#endif
