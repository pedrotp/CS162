/*********************************************************************

** Program Filename: Queue.cpp

** Author: Pedro Torres-Picon

** Date: 11/28/2016

** Description: Lab 9 - This is the implementation file for the Queue
class, which includes the source code for all the functions in the class.
A Queue is a first in first out (FIFO) data structure.

*********************************************************************/

#include "Queue.hpp"

/*********************************************************************

** Description: push()

** This function adds the given value to the back of the queue

*********************************************************************/

void Queue::push(int val) {

  storage.push_back(val);

};

/*********************************************************************

** Description: pop()

** This function removes and returns the item at the front of the queue

*********************************************************************/

int Queue::pop() {

  int item = -1;

  if (!storage.empty()) {
    item = storage.front();
    storage.pop_front();
  }

  return item;

};

/*********************************************************************

** Description: front()

** This function returns the value at the front of the queue

*********************************************************************/

int Queue::front() {

  int item = -1;

  if (!storage.empty()) {
    item = storage.front();
  }

  return item;

};

/*********************************************************************

** Description: empty()

** This function returns true if the queue is empty, false if it's not

*********************************************************************/

bool Queue::empty() {

  return storage.empty();

};

/*********************************************************************

** Description: size()

** This function returns the number of items currently in the queue

*********************************************************************/

int Queue::size() {

  return storage.size();

};
