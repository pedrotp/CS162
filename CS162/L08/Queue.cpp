/*********************************************************************

** Program Filename: Queue.cpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Lab 8 - This is the implementation file for the Queue
class, which includes the source code for all the functions in the class.
A Queue is a first in first out (FIFO) data structure.

*********************************************************************/

#include "Queue.hpp"

/*********************************************************************

** Description: Queue()

** This is the constructor for the Queue class, which creates the
Queue and sets the front and back pointers to 0

*********************************************************************/

Queue::Queue() {
  front = 0;
  back = 0;
};

/*********************************************************************

** Description: ~Queue()

** This is the destructor for the Queue class, which deallocates all
the memory for each node when the Queue is destroyed

*********************************************************************/

Queue::~Queue() {

  QueueNode *queuePtr = back;
  while (queuePtr) {
    QueueNode *garbage = queuePtr;
    if (queuePtr != queuePtr->next)
    queuePtr = garbage->next;
    delete garbage;
  }

};

/*********************************************************************

** Description: push()

** This function takes an integer value, adds it as the value of a
new node, and sets that node as the new tail node, updating all pointers
accordingly

*********************************************************************/

void Queue::push(int val) {

  QueueNode *queuePtr = tail;
  tail = new QueueNode(val);
  if (queuePtr) {
    tail->next = queuePtr;
    queuePtr->prev = tail;
  } else {
    head = tail;
  }

};

/*********************************************************************

** Description: pop()

** This function removes the head node from the front of the stack,
sets the previous node as the new head node, returns the value of the
removed node, and updates all pointers accordingly

*********************************************************************/

int Queue::pop() {

  int result = -1;

  if (head) {

    QueueNode *queuePtr = head;
    result = queuePtr->value;
    head = queuePtr->prev;
    delete queuePtr;

  } else {

    std::cout << "\nError: Queue is already empty, nothing to pop." << std::endl;

  }

  return result;

};
