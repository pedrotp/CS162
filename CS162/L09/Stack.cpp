/*********************************************************************

** Program Filename: Stack.cpp

** Author: Pedro Torres-Picon

** Date: 11/28/2016

** Description: Lab 9 - This is the implementation file for the Stack
class, which includes the source code for all the functions in the class.
A Stack is a first in last out (FILO) data structure.

*********************************************************************/

#include "Stack.hpp"

/*********************************************************************

** Description: push()

** This function adds the given value to the top of the stack

*********************************************************************/

void Stack::push(char ch) {

  storage.push_front(ch);

};

/*********************************************************************

** Description: pop()

** This function removes and returns the item at the top of the stack

*********************************************************************/

char Stack::pop() {

  char temp = storage.front();
  storage.pop_front();
  return temp;

};

/*********************************************************************

** Description: empty()

** This function returns true if the stack is empty, false if it's not

*********************************************************************/

bool Stack::empty() {

  return storage.empty();

};

/*********************************************************************

** Description: size()

** This function returns the number of items currently in the stack

*********************************************************************/

int Stack::size() {

  return storage.size();

};

/*********************************************************************

** Description: top()

** This function returns the value at the top of the stack

*********************************************************************/

char Stack::top() {

  return storage.front();

};
