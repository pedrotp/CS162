/*********************************************************************

** Program Filename: Item.hpp

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Assignment 2 - Part of a shopping cart program.
This is the interface file for the List class, which includes the
class, variable and function declarations.

*********************************************************************/

#include "Item.hpp"

#ifndef LIST_HPP
#define LIST_HPP

class List {

  private:
    Item *itemArr;
    int numItems; // variable to hold the number of items in the array
    int arrCapacity; // variable to hold the total current capacity of the array

  public:
    List();
    void addItems();
    void removeItems();
    void doubleCapacity();
    void print();
    ~List();

};

#endif
