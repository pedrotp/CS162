/*********************************************************************

** Program Filename: main.cpp

** Author: Pedro Torres-Picon

** Date: 11/07/2016

** Description: Lab 6 - A program that showcases Stack and Queue data
structures. This is the main file that uses all the classes to run
the program.

*********************************************************************/

#include "Stack.hpp"

int main() {

  Stack myStack;
  myStack.push(3);
  myStack.push(4);
  myStack.push(7);
  std::cout << myStack.pop() << std::endl;
  std::cout << myStack.pop() << std::endl;
  std::cout << myStack.pop() << std::endl;
  std::cout << myStack.pop() << std::endl;
  
  return 0;

};
