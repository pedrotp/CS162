
#include "sortsearch.hpp"

// Linear Search, Gaddis page 595
int linearSearch (int *array, int size, int target) {
  int pos = -1;
  int index = 0;
  while (pos == -1 && index < size) {
    if (array[index] == target) {
      pos = index;
    }
    index++;
  }
  return pos;
};

// Bubble Sort, Gaddis page 605
void bubbleSort (int *array, int size) {
  bool swap;
  do {
    swap = false;
    for (int index = 0; index < size - 1; index++) {
      if (array[index] > array[index + 1]) {
        int temp = array[index];
        array[index] = array[index + 1];
        array[index + 1] = temp;
        swap = true;
      }
    }
  } while (swap);
};

// Binary Search, Gaddis page 598
int binarySearch (int *array, int size, int target) {
  int first = 0;
  int last = size - 1;
  int middle;
  int pos = -1;
  while (pos == -1 && first <= last) { // [1, 2, 3, 4, 5, 6, 7, 8, 9]
    middle = (last + first) / 2;
    if (array[middle] == target) {
      pos = middle;
    } else if (array[middle] > target) {
      last = middle - 1;
    } else {
      first = middle + 1;
    }
  }
  return pos;
};

void printArr (int *array, int size) {
  std::cout << "[";
  for (int i = 0; i < size - 1; i++) {
    std::cout << array[i] << ", ";
  }
  std::cout << array[size - 1]<< "]";
};

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
