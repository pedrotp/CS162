/*********************************************************************

** Program Filename: Stack.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Lab 6 - This is the implementation file for the Stack
class, which includes the source code for all the functions in the class.
A Stack is a irst in last out (FILO) data structure.

*********************************************************************/

#include "Stack.hpp"

/*********************************************************************

** Description: Stack()

** This is the constructor for the Stack class, which creates the
Stack and sets the top pointer to 0

*********************************************************************/

Stack::Stack() {
  top = 0;
};

/*********************************************************************

** Description: Stack()

** This is the destructor for the Stack class, which deallocates all
the memory for each node when the Stack is destroyed

*********************************************************************/

Stack::~Stack() {

  StackNode *stackPtr = top;
  while (stackPtr) {
    StackNode *garbage = stackPtr;
    stackPtr = garbage->next;
    delete garbage;
  }

};

/*********************************************************************

** Description: push()

** This function takes an integer value, adds it as the value of a
new node, and sets that node as the top node, updating all pointers
accordingly

*********************************************************************/

void Stack::push(int val) {

  StackNode *stackPtr = top;
  top = new StackNode(val);
  top->next = stackPtr;

};

/*********************************************************************

** Description: pop()

** This function removes the top node from the stack, sets the
next node as the new top node, returns the value of the removed node,
and updates all pointers accordingly

*********************************************************************/

int Stack::pop() {

  int result = -1;

  if (top) {

    StackNode *stackPtr = top;
    result = stackPtr->value;
    top = stackPtr->next;
    delete stackPtr;

  } else {

    std::cout << "Error: Stack is already empty, nothing to pop." << std::endl;

  }

  return result;

};
