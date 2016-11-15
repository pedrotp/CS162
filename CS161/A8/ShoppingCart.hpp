/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/28/2016

** Description: Module 8, Assignment 8 -  Part of a shopping program
that allows the user to input different items (with price and quantity)
and get the total cost of all items in the cart. This portion creates
a ShoppingCart class that holds a group of items and can return the
total cost of all items it holds at any given time. This is the
interface file for the ShoppingCart class, that includes the class,
variable and function declarations.

*********************************************************************/

#ifndef SHOPPINGCART_HPP
#define SHOPPINGCART_HPP

#include "Item.hpp"

// Defines the interface of the ShoppingCart class
class ShoppingCart
{
  private:
    Item* array[100];
    int arrayEnd;

  public:
    ShoppingCart();
    void addItem(Item*);
    double totalPrice();

};
#endif
