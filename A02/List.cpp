/*********************************************************************

** Program Filename: List.cpp

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Assignment 2 - Part of a shopping cart program.
This is the implementation file for the List class, which includes the
source code for all the functions in the class.

*********************************************************************/

#include "List.hpp"

/*********************************************************************

** Function: List()

** Description: this is the default constructor for the List class
that sets all the variables to default values

*********************************************************************/

List::List() {
  itemArr = new Item[4];
  arrCapacity = 4;
  numItems = 0;
};

/*********************************************************************

** Function: addItems()

** Description: a function that adds items to the list by asking the
user to enter the name and quantity of the items to add, and also the
unit and price if it is a new item

*********************************************************************/

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

  // look for an item with the name entered, if found increase its quantity
  for (int i = 0; i < numItems; i++) {
    if (itemArr[i] == tempItem) {
      found = true;
      itemArr[i] = itemArr[i] + qtyNeeded;
      print();
    }
  }

  //if not found, ask the user for unit and price and add a new item to the storage array
  if (!found) {

    // if the array is at capacity double the capacity array
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

/*********************************************************************

** Function: removeItems()

** Description: a function that removes items from the list by asking
the user the name and quantity of items to remove

*********************************************************************/

void List::removeItems() {

  std::string itemName;
  int qtyRemove;

  std::cout << "Please enter the name of the item you wish to remove:" << std::endl;
  std::getline(std::cin, itemName);
  std::cout << "How many items of type " << itemName << " would you like to remove?" << std::endl;
  qtyRemove = getInt(0);

  Item tempItem(itemName, qtyRemove);
  bool found = false;

  // look for an item with the name give by the user, if found decrease the quantity by the number entered by the user
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

/*********************************************************************

** Function: doubleCapacity()

** Description: this function doubles the capacity of the storage
array by creating a new array and copying all the Items from the
first onto the second

*********************************************************************/

void List::doubleCapacity() {

  // create a new array with double the capacity of the current one
  Item *newArr = new Item[ arrCapacity * 2 ];

  //copy every item from the current array to the new larger one
  for (int i = 0; i < numItems; i++) {
    newArr[i] = itemArr[i];
  }

  // point the itemArr variable to the new array and deallocate the old array
  Item *tempPtr = itemArr;
  itemArr = newArr;
  delete[] tempPtr;

  // update the arrCapacity variable to reflect the new capacity
  arrCapacity *= 2;

};

/*********************************************************************

** Function: print()

** Description: prints the entire list to the screen with proper
formatting using the print() function from the individual Items plus
some extra information in the top and botton of the list

*********************************************************************/

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

/*********************************************************************

** Function: ~List()

** Description: this is the destructor, which deallocates the memory
allocated for the dynamic storage array itemArr

*********************************************************************/

List::~List() {
  delete[] itemArr;
};
