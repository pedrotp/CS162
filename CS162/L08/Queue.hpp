/*********************************************************************

** Program Filename: Queue.hpp

** Author: Pedro Torres-Picon

** Date: 11/21/2016

** Description: Lab 8 - This is the interface file for the Queue class,
which includes the class, variable and function declarations. A Queue
is a first in first out (FIFO) data structure.

*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

// Defines the QueueNode struct
struct QueueNode { // node definiton
  int value;
  QueueNode *prev; // pointer to the previous node in the queue
  QueueNode *next; // pointer to the next node in the queue
  QueueNode(int val) { // constructor
    value = val;
    prev = this;
    next = this;
  }
};

// Defines the interface of the Queue class
class Queue
{

  private:
    QueueNode *front; // pointer to the front of the queue
    QueueNode *back; // pointer to the back of the queue

  public:
    Queue();
    ~Queue();
    void addBack(int val); // adds a value to the back of the queue
    int getFront(); // returns the value at the front of the queue
    int removeFront(); // removes the value from the front of the queue, and returns it
    int displayContents(); // displays the contents of the queue

};

#endif
