/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/28/2016

** Description: Module 8, Assignment 8 -  Part of a shopping program
that allows the user to input different items (with price and quantity)
and get the total cost of all items in the cart. This portion creates
an Item class that has information about a particular item. This is the
interface file for the Item class, that includes the class, variable and
function declarations.

*********************************************************************/

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

// Defines the interface of the Item class
class Item
{
  private:
    std::string name;
    double price;
    int quantity;

  public:
    Item();
    Item(std::string, double, int);
    void setName(std::string);
    void setPrice(double);
    void setQuantity(int);
    std::string getName();
    double getPrice();
    int getQuantity();
    
};
#endif
