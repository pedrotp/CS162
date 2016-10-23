/*********************************************************************

** Program Filename: List.cpp

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Assignment 2 - Part of a shopping cart program.
This is the implementation file for the List class, which includes the
source code for all the functions in the class.

*********************************************************************/

#include "List.hpp"

List::List() {
  itemArr = new Item[4];
  arrCapacity = 4;
  numItems = 0;
};

void List::addItems() {

  std::string itemName;
  int qtyNeeded;
  std::string unitName;
  float unitPrice;

  std::cout << "Please enter the name of the item you wish to add:" << std::endl;
  std::getline(std::cin, itemName);
  std::cout << "How many items of type " << itemName << " would you like to add?" << std::endl;
  qtyNeeded = getInt(0);

  Item tempItem(itemName, qtyNeeded);
  bool found = false;

  for (int i = 0; i < numItems; i++) {
    if (itemArr[i] == tempItem) {
      found = true;
      itemArr[i] = itemArr[i] + qtyNeeded;
      print();
    }
  }

  if (!found) {

    if (numItems == arrCapacity) {
      doubleCapacity();
    }
    std::cout << "What is the unit of measurement for an item of type " << itemName << "?" << std::endl;
    std::getline(std::cin, unitName);
    tempItem.setUnit(unitName);
    std::cout << "How much does one " << unitName << " of " << itemName << " cost?" << std::endl;
    unitPrice = getFloat(0);
    tempItem.setPrice(unitPrice);

    itemArr[numItems] = tempItem;
    numItems++;
    print();

  }

};

void List::removeItems() {

  std::string itemName;
  int qtyRemove;

  std::cout << "Please enter the name of the item you wish to remove:" << std::endl;
  std::getline(std::cin, itemName);
  std::cout << "How many items of type " << itemName << " would you like to remove?" << std::endl;
  qtyRemove = getInt(0);

  Item tempItem(itemName, qtyRemove);
  bool found = false;

  for (int i = 0; i < numItems; i++) {
    if (itemArr[i] == tempItem) {
      found = true;
      itemArr[i] = itemArr[i] - qtyRemove;
      print();
    }
  }

  if (!found) {
    std::cout << "The item " << itemName << " was not found. Please try again." << std::endl;
  }

};

void List::doubleCapacity() {

  Item *newArr = new Item[ arrCapacity * 2 ];

  for (int i = 0; i < numItems; i++) {
    newArr[i] = itemArr[i];
  }

  Item *tempPtr = itemArr;
  itemArr = newArr;
  delete[] tempPtr;

  arrCapacity *= 2;

};

void List::print() {

  if (numItems > 0) {

    std::cout << "\nHere is your list:\n" << std::endl;
    std::cout << std::endl << std::string(85,'-') << std::endl;
    std::cout << std::left << std::setw(20) << "NAME" << std::right;
    std::cout << std::setw(15) << "QUANTITY";
    std::cout << std::setw(15) << "UNIT";
    std::cout << std::setw(15) << "PRICE";
    std::cout << std::setw(15) << "TOTAL PRICE";
    std::cout << std::endl << std::string(85,'-') << std::endl;

    float totalPrice = 0;

    for (int i = 0; i < numItems; i++) {
      totalPrice += itemArr[i].print();
    }

    std::cout << std::string(85,'-') << std::endl;
    std::cout << std::setw(65) << "TOTAL FOR ALL ITEMS:";
    std::cout << std::setw(15) << totalPrice;
    std::cout << std::endl << std::string(85,'-') << std::endl;

  } else {
    std::cout << "\nYour list is currently empty.\n" << std::endl;
  }

};

List::~List() {
  delete[] itemArr;
};
