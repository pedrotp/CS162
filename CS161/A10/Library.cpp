/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 08/05/2016

** Description: Module 10, Assignment 10 - This is part of a Library
program that keeps track of books and users in the library, and allows
patrons to request books on stand-by, check out and return books, and
keeps track of fines and payments. This is the implementation file for
the Library class which defines all the functions the class contains.
The Library class holds values and methods related to the library itself
and the actions that can be accomplished there.

*********************************************************************/

#include "Library.hpp"

/*********************************************************************

** Description:

** This is the defaut constructor that takes no parameters and sets
the currentDate of the library to a default value of 0.

*********************************************************************/

Library::Library()
{
  currentDate = 0;
}

/*********************************************************************

** Description: addBook()

** This function adds a new book to the library by adding a pointer to
it (provided as an argument) to holdings, which is a vector that stores
pointers to every book in the library.

*********************************************************************/

void Library::addBook(Book* b)
{
  holdings.push_back(b);
}

/*********************************************************************

** Description: addPatron()

** This function registers a new patron in the library by adding a
pointer to it to members, which is a vector that keeps track of all
the patrons in the library through pointers.

*********************************************************************/

void Library::addPatron(Patron* p)
{
  members.push_back(p);
}

/*********************************************************************

** Description: checkOutBook()

** This function checks out a particular book on behalf of a patron,
after checking that the book is available.

*********************************************************************/

std::string Library::checkOutBook(std::string pID, std::string bID)
{
  std::string result;
  Patron* ptn = getPatron(pID);
  Book* bk = getBook(bID);

  if (!bk) {
    result = "book not found";
  } else if (!ptn){
    result = "patron not found";
  } else if (bk->getLocation() == CHECKED_OUT) {
    result = "book already checked out";
  } else {
    if (bk->getRequestedBy() && bk->getRequestedBy() != ptn) {
      // if it's requested by someone other than this patron
      result = "book on hold by other patron";
    } else {
      bk->setCheckedOutBy(ptn);
      bk->setDateCheckedOut(currentDate);
      bk->setLocation(CHECKED_OUT);
      ptn->addBook(bk);
      if (bk->getRequestedBy() == ptn) {
        bk->setRequestedBy(NULL);
      }
      result = "check out successful";
    }
  }
  return result;
}

/*********************************************************************

** Description: returnBook()

**  This function takes a pointer to a book and returns that book if
it has been previously checked out

*********************************************************************/

std::string Library::returnBook(std::string bID)
{
  std::string result;
  Book* bk = getBook(bID);

  if (!bk) {
    result = "book not found";
  } else if (bk->getLocation() != CHECKED_OUT){
    result = "book already in library";
  } else {
    bk->getCheckedOutBy()->removeBook(bk); // might need parenthesis TEST
    bk->setCheckedOutBy(NULL);
    if (bk->getRequestedBy()){
      bk->setLocation(ON_HOLD_SHELF);
    } else {
      bk->setLocation(ON_SHELF);
    }
    result = "return successful";
  }
  return result;
}

/*********************************************************************

** Description: requestBook()

**  This function is used to put a book on request for a specified
patron. It checks to make sure the book is not already on request
and moves it to the hold shelf if it's on the shelf.

*********************************************************************/

std::string Library::requestBook(std::string pID, std::string bID)
{
  std::string result;
  Patron* ptn = getPatron(pID);
  Book* bk = getBook(bID);

  if (!bk) {
    result = "book not found";
  } else if (pID == "") { // added a facility to cancel a book request by inputting "" as a pID;
    if (bk->getRequestedBy()) {
      bk->setRequestedBy(NULL);
      if (bk->getLocation() == ON_HOLD_SHELF) {
        bk->setLocation(ON_SHELF);
      }
      result = "request cancelled";
    } else {
      result = "book not on hold";
    }
  } else if (!ptn){
    result = "patron not found";
  } else if (bk->getRequestedBy()) {
    result = "book already on hold";
  } else {
    bk->setRequestedBy(ptn);
    if (bk->getLocation() == ON_SHELF) {
      bk->setLocation(ON_HOLD_SHELF);
    }
    result = "request successful";
  }
  return result;
}

/*********************************************************************

** Description: payFine()

**  This function allows a patron to pay their fine. The amount entered
is deducted from the fine amount for the user corresponding to the userid
entered.

*********************************************************************/

std::string Library::payFine(std::string pID, double payment)
{
  std::string result;
  Patron* ptn = getPatron(pID);

  if (!ptn){
    result = "patron not found";
  } else {
    ptn->amendFine(-payment);
    result = "payment successful";
  }
  return result;
}

/*********************************************************************

** Description: incrementCurrentDate()

**  This function increments the current date by 1 "day" and makes sure
to add .10 in fines to patrons that have overdue books.

*********************************************************************/

void Library::incrementCurrentDate()
{
  currentDate++;
  for (int i = 0; i < members.size(); i++) {
    Patron* ptn = members.at(i);
    std::vector<Book*> ptnBooks = ptn->getCheckedOutBooks();
    for (int j = 0; j < ptnBooks.size(); j++) {
      if (currentDate - ptnBooks.at(j)->getDateCheckedOut() > 21) {
        ptn->amendFine(0.10);
      }
    }
  }
}

/*********************************************************************

** Description: getPatron()

**  Iterates through the vector that holds all the patrons until a
patron with the given ID is found, and then returns a pointer to it.
If a patron with that user ID is not found, then a pointer to NULL is
returned.

*********************************************************************/

Patron* Library::getPatron(std::string pID)
{
  Patron* result = NULL;
  for (int i = 0; i < members.size(); i++) {
    if (members.at(i)->getIdNum() == pID) {
      result = members.at(i);
    }
  }
  return result;
}

/*********************************************************************

** Description: getBook()

**  Iterates through the vector that holds all the books in the library
until a book with the given ID is found, and then returns a pointer to
that Book object. If a book with that ID is not found, then a pointer
to NULL is returned.

*********************************************************************/

Book* Library::getBook(std::string bID)
{
  Book* result = NULL;
  for (int i = 0; i < holdings.size(); i++) {
    if (holdings.at(i)->getIdCode() == bID) {
      result = holdings.at(i);
    }
  }
  return result;
}
