  #include "sortsearch.hpp"
  #include <fstream>
  #include <string>

  int main () {

    int algChoice;
    std::string fileName;
    std::ifstream ifs;
    int *array;
    int item; // variable that holds each item being read from the file
    int searchItem; // variable to hold the item the user wants to search for
    int size = 0;

    std::cout << "\nHi there, which algorithm do you want to test?" << std::endl;
    std::cout << "\n1: Linear Search" << std::endl;
    std::cout << "2: Bubble Sort" << std::endl;
    std::cout << "3: Binary Search" << std::endl;
    std::cout << "(Select 0 to Exit)\n" << std::endl;

    algChoice = getInt(0,3);

    if (algChoice) {
      std::cout << "\nGreat. Please enter the name of the file where I can find the numbers to work with:" << std::endl;
      do {
        std::getline(std::cin, fileName);
        ifs.open(fileName.c_str());
        if (!ifs) {
          std::cout << "\nWhoops! There was an error opening that file, please enter the file name again,\nand make sure the file is in the same directory as the executable file for this program,\nor it's file path is properly specified." << std::endl;
        }
      } while (!ifs);

      // first, count the number of integers in the file to know the size of the array
      while (ifs >> item) {
        size++;
      }

      array = new int[size];

      ifs.clear();
      ifs.seekg(0, std::ios::beg); // go back to the beginning of the file to read it again

      int index = 0;
      // loop again to store each item in the newly created array
      while (ifs >> item) {
        array[index++] = item;
      }

      std::cout << "\nOK, I got the array ";
      printArr(array, size);
      std::cout << " from the file '" << fileName << "'"<< std::endl;

      switch (algChoice) {

        case 1:
          std::cout << "Please enter an integer to search for: ";
          searchItem = getInt();
          std::cout << "Searching linearly for " << searchItem << "..." << std::endl;
          item = linearSearch(array, size, searchItem); // reuse the item variable
          if (item < 0) {
            std::cout << "The item " << searchItem << " was not found in the array." << std::endl;
          } else {
            std::cout << "Success! The item " << searchItem << " was found in position " << item << "." << std::endl;
          }
          break;

        case 2:
          std::cout << "Bubble sorting the array..." << std::endl;
          bubbleSort(array, size);
          std::cout << "RESULT: ";
          printArr(array, size);
          break;

        case 3:
        std::cout << "\nFirst, bubble sorting the array just in case..." << std::endl;
        bubbleSort(array, size);
        std::cout << "RESULT: ";
        printArr(array, size);

        std::cout << "\n\nPlease enter an integer to search for: ";
        searchItem = getInt();
        std::cout << "Binary searching for " << searchItem << "..." << std::endl;
        item = binarySearch(array, size, searchItem); // reuse the item variable
        if (item < 0) {
          std::cout << "The item " << searchItem << " was not found in the array." << std::endl;
        } else {
          std::cout << "Success! The item " << searchItem << " was found in position " << item << "." << std::endl;
        }
        break;

      }

      delete array;

    } else {

      std::cout << "\nGood bye!" << std::endl;

    }

    return 0;

  };
