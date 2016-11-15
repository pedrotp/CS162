/*********************************************************************

** Program Filename: Item.cpp

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Assignment 2 - Part of a shopping cart program.
This is the implementation file for the Item class, which includes the
source code for all the functions in the class.

*********************************************************************/

#include "Item.hpp"

/*********************************************************************

** Function: Item()

** Description: this is the default constructor for the Item class
that sets all the variables to default values

*********************************************************************/

Item::Item() {
  name = "NA";
  quantity = 0;
  unit = "NA";
  price = 0.0;
};

/*********************************************************************

** Function: Item()

** Description: a constructor for the item class that takes arguments
and stores them in private data variables

*********************************************************************/

Item::Item(std::string itemName, int qtyNeeded, std::string unitName, float unitPrice) {
  name = itemName;
  quantity = qtyNeeded;
  unit = unitName;
  price = unitPrice;
};

/*********************************************************************

** Function: print()

** Description: a function that prints the data for the Item to the
screen in a formatted line

*********************************************************************/

float Item::print() {
  float extPrice = quantity * price;
  if (quantity > 0) {
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::left << std::setw(20) << name << std::right;
    std::cout << std::setw(15) << quantity;
    std::cout << std::setw(15) << unit;
    std::cout << std::setw(15) << price;
    std::cout << std::setw(15) << extPrice;
    std::cout << std::endl;
  }
  return extPrice;
};

/*********************************************************************

** Function: setUnit()

** Description: a setter for the unit private variable

*********************************************************************/

void Item::setUnit(std::string unitName) {
  unit = unitName;
};

/*********************************************************************

** Function: setPrice()

** Description: a setter for the price private variable

*********************************************************************/

void Item::setPrice(float unitPrice) {
  price = unitPrice;
};

/*********************************************************************

** Function: ==operator()

** Description: overloads the == operator to compare Item names

*********************************************************************/

bool operator==(Item item1, Item item2) {
  return item1.name == item2.name;
};

/*********************************************************************

** Function: +operator()

** Description: overloads the + operator to add a number to the Item's
quantity private variable

*********************************************************************/

Item operator+(Item item1, int num) {
  item1.quantity += num;
  return item1;
};

/*********************************************************************

** Function: -operator()

** Description: overloads the - operator to subtract a number from the
Item's quantity private variable

*********************************************************************/

Item operator-(Item item1, int num) {
  if (num < item1.quantity) {
    item1.quantity -= num;
  } else {
    item1.quantity = 0; // enforces a minimum quantity of zero for items
  }
  return item1;
};
