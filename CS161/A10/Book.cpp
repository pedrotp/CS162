/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 08/05/2016

** Description: Module 10, Assignment 10 - This is part of a Library
program that keeps track of books and users in the library, and allows
patrons to request books on stand-by, check out and return books, and
keeps track of fines and payments. This is the implementation file for
the Book class which defines all the functions the class contains. The
Book class holds values and methods related to individual books.

*********************************************************************/

#include "Book.hpp"
#include <string>

/*********************************************************************

** Description:

** This is the default constructor that takes an ID code, a book title,
and an author and sets them internally. Here we also set the default
location for a book to ON_SHELF, and the checkedOutBy and requestedBy
values to NULL.

*********************************************************************/

Book::Book(std::string idc, std::string t, std::string a)
{
  idCode = idc;
  title = t;
  author = a;
  location = ON_SHELF;
  checkedOutBy = NULL;
  requestedBy = NULL;
}

int Book::getCheckOutLength()
{
  return CHECK_OUT_LENGTH;
}

std::string Book::getIdCode()
{
  return idCode;
}

std::string Book::getTitle()
{
  return title;
}

std::string Book::getAuthor()
{
  return author;
}

Locale Book::getLocation()
{
  return location;
}

void Book::setLocation(Locale loc)
{
  location = loc;
}

Patron* Book::getCheckedOutBy(){
  return checkedOutBy;
}

void Book::setCheckedOutBy(Patron* pat)
{
  checkedOutBy = pat;
}

Patron* Book::getRequestedBy()
{
  return requestedBy;
}

void Book::setRequestedBy(Patron* pat)
{
  requestedBy = pat;
}

int Book::getDateCheckedOut()
{
  return dateCheckedOut;
}

void Book::setDateCheckedOut(int dateCh)
{
  dateCheckedOut = dateCh;
}
