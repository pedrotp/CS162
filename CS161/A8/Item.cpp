/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/28/2016

** Description: Module 8, Assignment 8 -  Part of a shopping program
that allows the user to input different items (with price and quantity)
and get the total cost of all items in the cart. This portion creates
an Item class that has information about a particular item. This is the
implementation file for the Item class, which defines all the functions
the class contains.

*********************************************************************/

#include "Item.hpp"
#include <string>

/*********************************************************************

** Description:

** This is the default constuctor that sets the name to "", price to
0.0 and quantity to 0.

*********************************************************************/

Item::Item()
{
  setName("");
  setPrice(0.0);
  setQuantity(0);
}

/*********************************************************************

** Description:

** This is a constuctor that sets name, price and quantity to whatever
values the user provides

*********************************************************************/

Item::Item(std::string nameIn, double priceIn, int quantityIn)
{
  setName(nameIn);
  setPrice(priceIn);
  setQuantity(quantityIn);
}

void Item::setName(std::string nameIn)
{
  name = nameIn;
}

void Item::setPrice(double priceIn)
{
  price = priceIn;
}

void Item::setQuantity(int quantityIn)
{
  quantity = quantityIn;
}

std::string Item::getName()
{
  return name;
}

double Item::getPrice()
{
  return price;
}

int Item::getQuantity(){
  return quantity;
}
