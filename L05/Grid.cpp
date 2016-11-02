#include "Grid.hpp"
#include <unistd.h> // usleep

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
    std::cout << "STEP# " << s << std::endl;
  }
};

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

void Grid::getData() {
  // std::cout << "Please enter the number of steps you want the game to take" << std::endl;
  // numSteps = getInt(0);
  // std::cout << "Great. Now enter an integer for the size of the grid area" << std::endl;
  // std::cout << "(i.e. if you enter 10 we will generate a 10x10 grid)" << std::endl;
  // gridSize = getInt(0);
  // std::cout << "Awesome, now please enter the number of doodlebugs you want to start with" << std::endl;
  // numDoodles = getInt(0, gridSize * gridSize);
  // std::cout << "Finally, please enter the number of ants you want to start with" << std::endl;
  // numAnts = getInt(0, (gridSize * gridSize) - numDoodles);
  numSteps = 100;
  gridSize = 20;
  numDoodles = 5;
  numAnts = 100;
  std::cout << "\nOK, we are generating a " << gridSize << "x" << gridSize << " grid, and populating it with ";
  std::cout << numDoodles << " doodlebugs and " << numAnts << " ants. The game will go on for " << numSteps << " steps.\n" << std::endl;
};

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
  std::cout.flush();
  usleep(100000);
};

int Grid::getInt(int minSize, int maxSize) {
  int userInt;
  bool isValid = false;
  while (!isValid) {
    if (std::cin >> userInt && userInt >= minSize && userInt <= maxSize) {
      isValid = true;
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    } else {
      // std::cout << std::endl;
      std::cout << "Invalid input. Please enter an integer between " << minSize << " and " << maxSize << " (inclusive)." << std::endl;
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
  }
  return userInt;
};

Grid::~Grid() {
  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      if (grid[i][j] != 0) {
        delete grid[i][j]; // deallocate memory for every dynamically created critter
      }
    }
    delete [] grid[i]; // loop through the grid array and deallocate memory for each inner array
  }
  delete [] grid; // deallocate memory for the main array
};
