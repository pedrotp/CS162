/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Assignment 2 - Part of a shopping cart program.
This is the interface file for the List class, which includes the
class, variable and function declarations.

*********************************************************************/

#include <string>
#include "Item.hpp"

#ifndef LIST_HPP
#define LIST_HPP

class List {

  private:
    Item* itemArr;

  public:
    List();
    List();
    void addItem(Item newItem);
    void removeItem();

};

#endif

// You will also need a List class. You will store Item objects in your List object.
// When you enter a new item, an Item object must be created and added to the List object.
// Use a dynamic array to hold the Item objects. The dynamic array should start with a
// capacity of 4 Item objects. Do you need a print function in this class? Think about it.
