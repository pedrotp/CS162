/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Assignment 2 - Part of a shopping cart program.
This is the interface file for the Item class, which includes the
class, variable and function declarations.

*********************************************************************/

#include <string>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item {

  private:
    string name;
    string unit;
    int quantity;
    int unitPrice;

  public:
    Item();
    Item(int sides);

};

#endif

// You will design an Item class. The class should have data elements for the
// following information: item name, unit (i.e. can, box, pound, or ounce),
// quantity to buy, and unit price. Consider following things: do you need any
// functions other than the constructor(s)? How do you calculate the extended
// price for the item (quantity to buy times unit price)? How do you print it to the screen?
