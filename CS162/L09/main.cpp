/*********************************************************************

** Program Filename: main.cpp

** Author: Pedro Torres-Picon

** Date: 11/28/2016

** Description: Lab 9 - A program that showcases an implementation of
Queue and Stack data structures to simulate a buffer, and a palindrome
generator

*********************************************************************/

#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <ctime>

#include "Queue.hpp"
#include "Stack.hpp"

/*********************************************************************

** Description: getInt()

** Gets and validates integer input from the user, with the option of
entering a valid range for the int. If no minimum or maximum values
are entered, they are set to the min and max allowed for integers

*********************************************************************/

int getInt(int minSize = std::numeric_limits<int>::min(), int maxSize = std::numeric_limits<int>::max()) {

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

** Description: main()

** This is the driver function that runs the program, takes user input,
and shows user output to test the functionality of the stack and queue

*********************************************************************/

int main () {

  srand (std::time(NULL));

  Queue buffer;
  Stack palindrome;
  std::cout << "\nHey there! Welcome to the Stack and Queue test program" << std::endl;

  bool exitFlag = false;
  while (!exitFlag) {

    std::cout << "\nWhat do you want to do?" << std::endl;
    std::cout << "\n1. Test the Buffer" << std::endl;
    std::cout << "2. Test the Palindrome" << std::endl;
    std::cout << "(Select 0 to exit)\n" << std::endl;

    std::string word;
    int insChance;
    int remChance;
    int rounds;
    int item;

    switch (getInt(0,2)) {

      case 0:

        std::cout << "\nGood bye!\n" << std::endl;
        exitFlag = true;

        break;

      case 1:

        std::cout << "\nPlease enter the % chance of an item being inserted into the queue:" << std::endl;
        insChance = getInt(0,100);
        std::cout << "\nGreat. Please enter the % chance of an item being removed from the queue:" << std::endl;
        remChance = getInt(0,100);
        std::cout << "\nOk. How many rounds should we run?" << std::endl;
        rounds = getInt(0,100);
        std::cout << std::endl;

        for (int i = 0; i < rounds; i++) {

          std::cout << "\nRound " << i + 1 << ":" << std::endl;

          item = rand() % 100 + 1;
          if (item < insChance) {
            buffer.push(item);
            std::cout << "Item added to the buffer." << std::endl;
          }

          item = rand() % 100 + 1;
          if (item < remChance && buffer.front() != -1) {
            buffer.pop();
            std::cout << "Item removed from the buffer." << std::endl;
          }

        }

        if (buffer.front() != -1) {
          std::cout << "\nThe final contents of the buffer are: " << buffer.pop();
          while (buffer.front() != -1) {
            std::cout << ", " << buffer.pop();
          }
          std::cout << std::endl;
        }

        break;

      case 2:
        std::cout << "\nPlease enter a word, and I will return its palindrome: ";
        std::getline(std::cin, word);

        std::cout << "\nOK. The word is: " << word << std::endl;

        for (int i = 0; i < word.size(); i++) {
          palindrome.push(word.at(i));
        }

        std::cout << "The palindrome is: ";
        while (!palindrome.empty()) {
          std::cout << palindrome.pop();
        }
        std::cout << "\n" << std::endl;

    }

  }

  return 0;

};
