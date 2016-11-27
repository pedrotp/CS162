/*********************************************************************

** Program Filename: Queue.hpp

** Author: Pedro Torres-Picon

** Date: 11/28/2016

** Description: Lab 9 - This is the interface file for a Queue class,
which includes the class, variable and function declarations. A Queue
is a first in first out (FIFO) data structure.

*********************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <deque>

// Defines the interface of the Queue class
class Queue
{

  private:
    std::deque<int> storage;

  public:
    void push(int val); // adds a value to the tail of the queue
    int pop(); // removes a value from the head of the queue
    int front();
    bool empty();
    int size();

};

#endif
