/*********************************************************************

** Program Filename: Item.cpp

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Assignment 2 - Part of a shopping cart program.
This is the implementation file for the Item class, which includes the
source code for all the functions in the class.

*********************************************************************/

#include "Item.hpp"

Item::Item() {
  name = "NA";
  quantity = 0;
  unit = "NA";
  price = 0.0;
};

Item::Item(std::string itemName, int qtyNeeded, std::string unitName, float unitPrice) {
  name = itemName;
  quantity = qtyNeeded;
  unit = unitName;
  price = unitPrice;
};

std::string Item::getName() {
  return name;
};

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

void Item::setUnit(std::string unitName) {
  unit = unitName;
};

void Item::setPrice(float unitPrice) {
  price = unitPrice;
};

bool operator==(Item item1, Item item2) {
  return item1.getName() == item2.getName();
};

Item operator+(Item item1, int num) {
  item1.quantity += num;
  return item1;
};

Item operator-(Item item1, int num) {
  if (num < item1.quantity) {
    item1.quantity -= num;
  } else {
    item1.quantity = 0;
  }
  return item1;
};
