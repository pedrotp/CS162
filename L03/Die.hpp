/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/17/2016

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
