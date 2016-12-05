/*********************************************************************

** Program Filename: FormsDept.hpp

** Author: Pedro Torres-Picon

** Date: 12/07/2016

** Description: Final Project - Part of a single-player game depicting
the challenge of navigating the DMV. This is the implementation file
for the FormsDept class, which is derived from the Room class. This
file includes the source code for all the functions in the class.

*********************************************************************/

#include "FormsDept.hpp"

FormsDept::FormsDept(Player* p1) : Room(p1){

};

Room* FormsDept::play() {

  std::cout << "Current room: Forms Department\n\n" << std::endl;
  
  return nextStep();

};
