/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/28/2016

** Description: Module 8, Assignment 8 -  Part of a shopping program
that allows the user to input different items (with price and quantity)
and get the total cost of all items in the cart. This portion creates
a ShoppingCart class that holds a group of items and can return the
total cost of all items it holds at any given time. This is the
implementation file for the ShoppingCart class, which defines all
the functions the class contains.

*********************************************************************/

#include "ShoppingCart.hpp"

/*********************************************************************

** Description:

** This is the default constuctor that initializes each element of the
array to NULL and initializes arrayEnd to zero

*********************************************************************/

ShoppingCart::ShoppingCart()
{
  for (int count = 0; count < 100; count++)
  {
    array[count] = NULL;
  }
  arrayEnd = 0;
}

/*********************************************************************

** Description: addItem()

** This function takes as a parameter a pointer to an Item and adds it
to the array. Then it updates arrayEnd by adding 1 to it.

*********************************************************************/

void ShoppingCart::addItem(Item* newItem)
{
  array[arrayEnd++] = newItem;
}

/*********************************************************************

** Description: totalPrice()

** This function returns the total cost of all Items in the ShoppingCart

*********************************************************************/

double ShoppingCart::totalPrice()
{
  double total = 0;
  for (int index = 0; index < arrayEnd; index++) {
    double itemPrice = array[index]->getPrice() * array[index]->getQuantity();
    total += itemPrice;
  }
  return total;
}
