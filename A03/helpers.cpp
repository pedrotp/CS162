#include "helpers.hpp"

int getInt(int minSize, int maxSize) {

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
