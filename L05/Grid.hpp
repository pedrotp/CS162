#ifndef GRID_HPP
#define GRID_HPP

#include <iostream>
#include "Ant.hpp"
#include "Doodlebug.hpp"

// Defines the interface of the Grid class
class Grid
{
  private:
    Critter ***grid; // pointer variable for the matrix where the critter moves around
    int gridSize; // variable to hold the size of matrix
    int numSteps;
    int numAnts;
    int numDoodles;

  public:
    // Grid();
    void play();
    void makeGrid();
    void getData();
    void print();
    int getInt(int minSize = std::numeric_limits<int>::min(), int maxSize = std::numeric_limits<int>::max()); // helper function to validate int input
    ~Grid();
    //helpers
};

#endif
