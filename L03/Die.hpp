/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/15/2016

** Description: Lab 3 - Part of a simplified game of War, with dice.
This is the interface file for the Die class, which includes the
class, variable and function declarations.

*********************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

class Die {

  private:
    int numSides; // to hold the number of sides of the die

  public:
    Die();
    Die(int sides);
    int getSides();
    virtual int roll();
};

#endif

// changes from design, had to make it a pointer and dynamically allocate the array
// included a destructor to deallocate the memory
// changed from using an array for the sides to just an int
