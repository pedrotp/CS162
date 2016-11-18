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

#include "List.hpp"

// Defines the interface of the Stack class
class Stack : public List
{

  protected:
    struct StackNode { // node definition
      Creature* value;
      StackNode *next; // pointer to the next node in the stack
      StackNode(Creature* val) { // constructor
        value = val;
        next = 0;
      }
    };
    StackNode *top; // pointer to the top of the stack

  public:
    Stack();
    ~Stack();
    void push(Creature* val); // adds a value to the top of the stack
    Creature* pop(); // removes a value from the top of the stack

};

#endif
