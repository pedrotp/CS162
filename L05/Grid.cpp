/*********************************************************************

** Program Filename: Grid.cpp

** Author: Pedro Torres-Picon

** Date: 11/02/2016

** Description: Lab 5 - Part of a predator/prey simulation.
This is the implementation file for the Grid class, which includes the
source code for all the functions in the class.

*********************************************************************/

#include "Grid.hpp"
#include <unistd.h> // usleep

/*********************************************************************

** Description: play()

** This is the main function that runs the simulation from within
the Grid class

*********************************************************************/

void Grid::play() {
  std::cout << "Hi there, welcome to the Critter game!" << std::endl;
  std::cout << "***** EXTRA CREDIT MODE UNLOCKED *****\n" << std::endl;
  getData();
  makeGrid();
  for (int s = 0; s < numSteps; s++) {
    for (int i = 0; i < gridSize; i++) {
      for (int j = 0; j < gridSize; j++) {
        if (grid[i][j] && grid[i][j]->type() == "Doodlebug") {
          if (!(grid[i][j]->step(s))) {
            delete grid[i][j];
            grid[i][j] = 0;
          }
        }
      }
    }
    for (int i = 0; i < gridSize; i++) {
      for (int j = 0; j < gridSize; j++) {
        if (grid[i][j] && grid[i][j]->type() == "Ant") {
          grid[i][j]->step(s);
        }
      }
    }
    print();

    std::cout.flush();
    usleep(30000);
  }
  std::cout << "That's the end. Would you like to run the simulation again? (y/n)" << std::endl;
};

/*********************************************************************

** Description: makeGrid()

** This function creates a new grid, stores it in a pointer, and
populates it with the proper number of Doodlebugs and Ants

*********************************************************************/

void Grid::makeGrid() {
  // make and populate a new grid with 0's
  grid = new Critter**[gridSize]; // create a new double pointer that points to an array
  for (int i = 0; i < gridSize; i++) {
    grid[i] = new Critter*[gridSize]; // loop through the matrix array and make sure each pointer points to an array of Critter pointers
    for (int j = 0; j < gridSize; j++) {
      grid[i][j] = 0; // loop through the inner arrays and set every Critter pointer to 0
    }
  }

  // fill the grid with the requested number of doodles in random locations
  for (int i = 0; i < numDoodles; i++) {
    int randx = rand() % gridSize;
    int randy = rand() % gridSize;
    if (!grid[randx][randy]) {
      grid[randx][randy] = new Doodlebug(grid,gridSize,randx,randy);
    } else {
      i--;
    }
  }

  // fill the grid with the requested number of ants in random locations
  for (int i = 0; i < numAnts; i++) {
    int randx = rand() % gridSize;
    int randy = rand() % gridSize;
    if (!grid[randx][randy]) {
      grid[randx][randy] = new Ant(grid,gridSize,randx,randy);
    } else {
      i--;
    }
  }

};

/*********************************************************************

** Description: getData()

** This function asks the user to enter all the data necessary to run
the simulation, according to the extra credit

*********************************************************************/

void Grid::getData() {
  std::cout << "Please enter the number of steps you want the game to take" << std::endl;
  numSteps = getInt(0);
  std::cout << "Great. Now enter an integer for the size of the grid area" << std::endl;
  std::cout << "(i.e. if you enter 10 we will generate a 10x10 grid)" << std::endl;
  gridSize = getInt(0);
  std::cout << "Awesome, now please enter the number of doodlebugs you want to start with" << std::endl;
  numDoodles = getInt(0, gridSize * gridSize);
  std::cout << "Finally, please enter the number of ants you want to start with" << std::endl;
  numAnts = getInt(0, (gridSize * gridSize) - numDoodles);

  std::cout << "\nOK, we are generating a " << gridSize << "x" << gridSize << " grid, and populating it with ";
  std::cout << numDoodles << " doodlebugs and " << numAnts << " ants. The game will go on for " << numSteps << " steps.\n" << std::endl;
};

/*********************************************************************

** Description: print()

** This function clears the terminal screen first, then prints the
grid to the screen, printing a specific character to represent
blank spaces, Ants and Doodlebugs.

*********************************************************************/

void Grid::print() {
  std::cout << "\033[2J\033[1;1H";
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      if (!grid[i][j]) {
        std::cout << " ";
      } else if (grid[i][j]->type() == "Ant"){
        std::cout << "O";
      } else if (grid[i][j]->type() == "Doodlebug"){
        std::cout << "X";
      }
    }
    std::cout << std::endl;
  }
};


/*********************************************************************

** Description: getInt()

** Helper function which asks the user for an integer value,
validates that input and returns it.

*********************************************************************/

int Grid::getInt(int minSize, int maxSize) {
  int userInt;
  bool isValid = false;
  while (!isValid) {
    if (std::cin >> userInt && userInt >= minSize && userInt <= maxSize) {
      isValid = true;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } else {
      std::cout << "Invalid input. Please enter an integer between " << minSize << " and " << maxSize << " (inclusive)." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }
  return userInt;
};

/*********************************************************************

** Description: ~Grid()

** This is the destructor for the Grid class that deallocates memory
for all arrays in the grid, as well as all the pointers to Critter

*********************************************************************/

Grid::~Grid() {
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      delete grid[i][j]; // deallocate memory for every dynamically created critter
    }
    delete [] grid[i]; // loop through the grid array and deallocate memory for each inner array
  }
  delete [] grid; // deallocate memory for the main array
};
