#include "Library.hpp"
#include <iostream>

int main() {
  Book b1("123", "War and Peace", "Tolstoy");
  Book b2("234", "Moby Dick", "Melville");
  Book b3("345", "Phantom Tollbooth", "Juster");
  Patron p1("abc", "Felicity");
  Patron p2("bcd", "Waldo");
  Patron p3("ped", "Pedro");
  Library lib;
  lib.addBook(&b1);
  lib.addBook(&b2);
  lib.addBook(&b3);
  lib.addPatron(&p1);
  lib.addPatron(&p2);
  lib.addPatron(&p3);
  std::cout << lib.checkOutBook("bcd", "234") << std::endl;
  for (int i=0; i<7; i++)
     lib.incrementCurrentDate();
  std::cout << "b1 location before checkout (should be 0): "<< b1.getLocation() << std::endl;
  std::cout << lib.checkOutBook("bcd", "123") << std::endl;
  std::cout << lib.checkOutBook("abc", "345") << std::endl;
  for (int i=0; i<24; i++)
     lib.incrementCurrentDate();
  std::cout << lib.payFine("bcd", 0.4) << std::endl;
  std::cout << lib.requestBook("abc", "123") << std::endl;
  std::cout << "b1 location before return (should be 2): "<< b1.getLocation() << std::endl;
  std::cout << lib.returnBook("123") << std::endl;
  std::cout << lib.returnBook("345") << std::endl;
  std::vector<Book*> p2Books = p2.getCheckedOutBooks();
  std::cout << "p2's books (should not include 123): ";
  for (int i = 0; i < p2Books.size(); i++) {
    std::cout << p2Books.at(i)->getIdCode() << " ";
  }
  std::cout << std::endl;
  std::cout << "b1 location after return (should be 1): "<< b1.getLocation() << std::endl;
  std::cout << "b3 location after return (should be 0): "<< b3.getLocation() << std::endl;
  std::cout << "wrong patron tries to check out a reserved book: " << lib.checkOutBook("ped","123") << std::endl;
  std::cout << "right patron tries to check out a reserved book: " << lib.checkOutBook("abc","123") << std::endl;
  std::cout << "b1 location after check out from hold shelf (should be 2): "<< b1.getLocation() << std::endl;
  std::cout << lib.requestBook("ped","345") << std::endl;
  std::cout << "b3 location after request from shelf (should be 1): "<< b3.getLocation() << std::endl;
  std::cout << lib.requestBook("","345") << std::endl;
  std::cout << "b3 location after request cancelled (should be 0): "<< b3.getLocation() << std::endl;
  double p1Fine = p1.getFineAmount();
  double p2Fine = p2.getFineAmount();
  std::cout << "p1 fine: " << p1Fine << std::endl;
  std::cout << "p2 fine: " << p2Fine << std::endl;
  return 0;
}
