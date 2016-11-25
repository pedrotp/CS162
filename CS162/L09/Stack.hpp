/*********************************************************************

** Program Filename: Stack.hpp

** Author: Pedro Torres-Picon

** Date: 11/28/2016

** Description: Lab 9 - This is the interface file for a Stack class,
which includes the class, variable and function declarations. A Stack
is a first in last out (FILO) data structure.

*********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <deque>

// Defines the interface of the Stack class
class Stack
{

  private:
    std::deque<char> storage;

  public:
    void push(char ch); // adds a value to the tail of the stack
    char pop(); // removes a value from the head of the stack
    bool empty();
    int size();
    char top();

};

#endif
