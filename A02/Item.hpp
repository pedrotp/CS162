/*********************************************************************

** Program Filename: Item.hpp

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Assignment 2 - Part of a shopping cart program.
This is the interface file for the Item class, which includes the
class, variable and function declarations.

*********************************************************************/

#include <string>
#include "helpers.hpp"
#include <iomanip>

#ifndef ITEM_HPP
#define ITEM_HPP

class Item {

  private:
    std::string name;
    int quantity;
    std::string unit;
    float price;

  public:
    Item();
    Item(std::string itemName, int qtyNeeded, std::string unitName = "", float unitPrice = 0);
    std::string getName();
    float print(); // returns the 'extended price' for the item after printing
    void setUnit(std::string unitName);
    void setPrice(float unitPrice);
    friend bool operator==(Item item1, Item item2);
    friend Item operator+(Item item1, int num);
    friend Item operator-(Item item1, int num);

};

#endif

// changes:
// make unit of measurement and price optional
// print function returns the total price for that item
