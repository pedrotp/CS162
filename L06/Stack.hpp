/*********************************************************************

** Program Filename: Stack.hpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Lab 6 - This is the interface file for a Stack class,
which includes the class, variable and function declarations. A Stack
is a first in last out (FILO) data structure.

*********************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

// Defines the interface of the Stack class
class Stack
{

  protected:
    struct StackNode {
      int value;
      StackNode *next;
      StackNode(int val) {
        value = val;
        next = nullptr;
      }
    };
    StackNode *top;

  public:
    Stack();
    void push(int val);
    int pop();

};

#endif
