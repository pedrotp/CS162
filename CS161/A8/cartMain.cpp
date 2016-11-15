/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/28/2016

** Description: Module 8, Assignment 8 -  Test file

*********************************************************************/

#include <iostream>
#include <string>
#include "ShoppingCart.hpp"

using namespace std;

int main()
{
  Item a("affidavit", 179.99, 12);
  Item b("Bildungsroman", 0.7, 20);
  Item c("capybara", 4.5, 6);
  Item d("dirigible", 0.05, 16);
  ShoppingCart sc1;
  sc1.addItem(&a);
  sc1.addItem(&b);
  sc1.addItem(&c);
  sc1.addItem(&d);
  double diff = sc1.totalPrice();

  cout << "total price is " << diff;

  return 0;
}
