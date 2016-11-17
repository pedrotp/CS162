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

  front = new QueueNode(-1);
  back = front;
};

/*********************************************************************

** Description: ~Queue()

** This is the destructor for the Queue class, which deallocates all
the memory for each node when the Queue is destroyed

*********************************************************************/

Queue::~Queue() {

  QueueNode *queuePtr = front;

  while (queuePtr->next != front) {
    QueueNode *garbage = queuePtr;
    queuePtr = garbage->next;
    delete garbage;
  }

  delete queuePtr;

};

/*********************************************************************

** Description: addBack()

** This function adds a value to the back of the queue. If there is
already an empty node at the back, it sets the value of that node to
the added value, and updates pointers accordingly. If not, a new node
is created with the value, and pointers are updated accordingly.

*********************************************************************/

void Queue::addBack(int val) {

  if (back->next->value == -1) {
    back->next->value = val;
  } else { // back->next == front
    back->next = new QueueNode(val);
    back->next->next = front;
    back->next->prev = back;
    front->prev = back->next;
  }
  back = back->next;

};

/*********************************************************************

** Description: getFront()

** This function returns the value of the current front node, or -1
as an error value if the queue is empty

*********************************************************************/

int Queue::getFront() {

  return front->value;

};

/*********************************************************************

** Description: removeFront()

** This function sets the value of the current front node to -1, sets
the next node as the new front, returns the value of the removed node,
and updates all pointers accordingly. If the queue is empty, it returns
-1 as an error value

*********************************************************************/

int Queue::removeFront() {

  int result = front->value;

  if (result != -1) {

    front->value = -1;
    front = front->next;

  }

  return result;

};

/*********************************************************************

** Description: displayContents()

** This function displays all the values in the queue starting at the
front, and going all the way to the back. It skips empty nodes between
the back and front. If the queue was displayed, it returns 0, if the
queue was empty, it returns -1 as an error value.

*********************************************************************/

int Queue::displayContents() {
  int error = 0;
  if (front->value != -1) {

    std::cout << front->value << " ";

    QueueNode *queuePtr = front;

    while (queuePtr != back) {
      queuePtr = queuePtr->next;
      std::cout << queuePtr->value << " ";
    }

  } else {
    error = -1;
  }

  return error;
  
};
