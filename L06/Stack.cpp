/*********************************************************************

** Program Filename: Stack.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Lab 6 - This is the implementation file for the Stack
class, which includes the source code for all the functions in the class.
A Stack is a irst in last out (FILO) data structure.

*********************************************************************/

#include "Stack.hpp"

Stack::Stack() {
  top = nullptr;
};

void Stack::push(int val) {

  StackNode *stackPtr = top;
  top = new StackNode(val);
  top->next = stackPtr;

};

int Stack::pop() {

  int result = -1;

  if (top != nullptr) {

    StackNode *stackPtr = top;
    result = top->value;
    top = stackPtr->next;
    delete stackPtr;

  } else {

    std::cout << "Error: Stack is already empty, nothing to pop." << std::endl;

  }

  return result;

};
