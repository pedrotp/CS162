/*********************************************************************

** Program Filename: List.hpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Lab 6 - This is the interface file for a List abstract
class, which just defines two pure virtual functions which will be later
implemented by the Stack and Queue classes

I created this superclass so that I could do just one implementation
in my main() function with a List pointer that can point to either a
Stack or a Queue

*********************************************************************/

#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

// Defines the interface of the List class
class List
{

  public:
    virtual void push(int val) = 0;
    virtual int pop() = 0;

};

#endif
