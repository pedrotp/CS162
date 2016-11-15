/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 08/05/2016

** Description: Module 10, Assignment 10 - This is part of a Library
program that keeps track of books and users in the library, and allows
patrons to request books on stand-by, check out and return books, and
keeps track of fines and payments. This is the implementation file for
the Patron class which defines all the functions the class contains.
The Patron class holds values and methods related to individual library
patrons.

*********************************************************************/

#include "Patron.hpp"
#include <iostream>

/*********************************************************************

** Description:

** This is the constructor which takes an ID number and a name for a
patron and sets those values internally. Here, we also set the default
value of the fine amount to 0.

*********************************************************************/

Patron::Patron(std::string idn, std::string n)
{
  idNum = idn;
  name = n;
  fineAmount = 0;
}

std::string Patron::getIdNum()
{
  return idNum;
}

std::string Patron::getName()
{
  return name;
}

std::vector<Book*> Patron::getCheckedOutBooks()
{
  return checkedOutBooks;
}

/*********************************************************************

** Description: addBook()

** This function takes a pointer to a Book and adds it to checkedOutBooks,
which is a vector that keeps track of all the books the Patron has
checked out.

*********************************************************************/

void Patron::addBook(Book* b)
{
  checkedOutBooks.push_back(b);
}

/*********************************************************************

** Description: removeBook()

** This function takes a pointer to a Book, finds that pointer within
checkedOutBooks and deletes it.

*********************************************************************/

void Patron::removeBook(Book* b)
{
  for (int i = 0; i < checkedOutBooks.size(); i++) {
    if (checkedOutBooks.at(i) == b) {
        checkedOutBooks.erase(checkedOutBooks.begin()+i);
    }
  }
}

double Patron::getFineAmount()
{
  return fineAmount;
}

/*********************************************************************

** Description: amendFine()

** This function takes a double quantity and adds (or removes if the
quantity is negative) it from the fineAmount. 

*********************************************************************/

void Patron::amendFine(double amount)
{
  fineAmount += amount;
}
