/*********************************************************************

** Program Filename: FibonacciNR.hpp

** Author: Pedro Torres-Picon

** Date: 12/05/2016

** Description: Lab 10 - This is the main file that runs the entire
program, tests the recursive and non recursive functions, measures
their execution time and prints everythign to the screen.

*********************************************************************/

#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include "FibonacciR.hpp"
#include "FibonacciNR.hpp"
using namespace std;

int main() {

  // using unsigned long long to hold the largest fibonacci numbers possible
  unsigned long long n = 1;

  while (n < 94) { // only run until the 93rd fibonacci number because of storage capacity

    clock_t t1, t2; // declare both time variables

    cout << "Finding " << n << "th fibonacci number....\n" << endl;

    if (n < 51) { // only apply the recursive function to numbers 50 and below

      ofstream ofs;
      ofs.open("recursive.txt", ios::app); // save time results in a text file

      cout << "Calling Recursive Fibonacci implementation" << endl;
      FibonacciR fibr(n);
      t1 = clock(); // start time
      fibr.PrintFibonacci();
      t1 = clock() - t1; // start - end time
      cout << "Time to execute: " << t1 << " clicks (" << t1/CLOCKS_PER_SEC << " seconds)\n" << endl;

      ofs << t1 << "\n";
      ofs.close();

    }

    ofstream ofs;
    ofs.open("non_recursive.txt", ios::app); // save time results in a text file

    cout << "Calling Non-Recursive Fibonacci implementation" << endl;
    FibonacciNR fibnr(n);
    t2 = clock(); // start time
    fibnr.PrintFibonacci();
    t2 = clock() - t2; // start - end time
    cout << "Time to execute: " << t2 << " clicks (" << t2/CLOCKS_PER_SEC << " seconds)\n" << endl;

    ofs << t2 << "\n";
    ofs.close();

    n += 1;

  }

  cout << "\nThat's all folks!\n" << endl;

  return 0;

}
