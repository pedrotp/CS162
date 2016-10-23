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
    int numItems;
    int arrCapacity;

  public:
    List();
    void addItems();
    void removeItems();
    void doubleCapacity();
    void print();
    ~List();

};

#endif

// changes
// thought addItems would take an Item but it takes the parameters and creates the item internally
