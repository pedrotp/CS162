/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 11/02/2016

** Description: Lab 5 - this is the main file that runs the program

*********************************************************************/

#include "Grid.hpp"


/*********************************************************************

** Description: getYesNo()

** Helper function which asks the user for a char value of y or n,
validates that input and returns it in boolean form.

*********************************************************************/

bool getYesNo() {
  char yn;
  bool isValid = false;
  while (!isValid) {
    std::cin >> yn;
    if (yn == 'Y' || yn == 'y') {
      yn = 'y';
      isValid = true;
    } else if (yn == 'N' || yn == 'n'){
      yn = 'n';
      isValid = true;
    } else {
      std::cout << "Invalid input. Please enter y or n only." << std::endl;
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
  }
  return !!(yn == 'y');
};

/*********************************************************************

** Description: main()

** This is the main function that creates a grid and runs the
simulation

*********************************************************************/

int main() {

  do {

    Grid *myGrid = new Grid;
    myGrid->play();
    delete myGrid;

  } while (getYesNo());

  return 0;
};
