/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/23/2016

** Description: Lab 4 - This assignment includes 3 functions that
demonstrate recursion. This is the main program that demonstrates all
three recursive function.

*********************************************************************/

#include "recursion.hpp"

int main () {
  int menuChoice;
  std::string revStr; // string to be reversed
  do {
    // instructions
    std::cout << "\nWelcome! Please choose an option from the following menu:\n" << std::endl;
    std::cout << "1. Reverse a string" << std::endl;
    std::cout << "2. Sum the elements of an array" << std::endl;
    std::cout << "3. Calculate a triangular number" << std::endl;
    std::cout << "\nEnter 0 to exit the program\n" << std::endl;
    switch (menuChoice = getInt(0,3)) {
      case 1:
        // reverseString
        std::cout << "\nPlease enter a string and I will reverse it.\n" << std::endl;
        std::getline(std::cin,revStr);
        reverseString(revStr);
        break;

      case 2:
        // sumArray
        std::cout << "\nPlease enter a sequence of numbers to create an array." << std::endl;
        std::cout << "Each number should be followed by the enter key." << std::endl;
        std::cout << "Enter the number 0 to end the sequence and calculate the sum.\n" << std::endl;
        // I used 0 as the delimiter because adding 0 to the other numbers in the array has no effect
        int bigArr[128];
        int count, addNum;
        count = 0;
        addNum = 1;
        while (count < 128 && addNum != 0) {
          addNum = getInt();
          bigArr[count] = addNum;
          count++;
        }
        if (count == 128) {
          std::cout << "Max array size reached!" << std::endl;
        } else {
          count--; // ignore the last element which will be zero
        }
        std::cout << "Your array is ";
        printArray(bigArr, count);
        std::cout << std::endl;
        std::cout << "The sum of all the array elements is: " << sumArray(bigArr,count) << std::endl;
        break;

      case 3:
        // triangularNumber
        std::cout << "\nPlease enter an integer and I will print the corresponding triangular number.\n" << std::endl;
        int triNum;
        triNum = getInt(0); // get a non-negative integer
        std::cout << "You entered " << triNum << "; the triangular number is " << triangularNumber(triNum) << "." << std::endl;
        break;

      default:
        std::cout << "\nGood bye!\n" << std::endl;
        break;
    }
  } while (menuChoice); // while the meny choice is not zero

  return 0;
};
