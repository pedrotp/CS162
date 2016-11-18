/*********************************************************************

** Program Filename: Queue.hpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Lab 6 - This is the interface file for a Queue class,
which includes the class, variable and function declarations. A Queue
is a first in first out (FIFO) data structure.

*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "List.hpp"
// Defines the interface of the Queue class
class Queue : public List
{

  protected:
    struct QueueNode { // node definiton
      Creature *value;
      QueueNode *prev; // pointer to the previous node in the queue
      QueueNode *next; // pointer to the previous node in the queue
      QueueNode(Creature *val) { // constructor
        value = val;
        prev = 0;
        next = 0;
      }
    };
    QueueNode *head; // pointer to the head (front) of the queue
    QueueNode *tail; // pointer to the tail (back) of the queue

  public:
    Queue();
    ~Queue();
    void push(Creature *val); // adds a value to the tail of the queue
     Creature *pop(); // removes a value from the head of the queue

};

#endif
