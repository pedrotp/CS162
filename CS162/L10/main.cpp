#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <fstream>
#include "FibonacciR.hpp"
#include "FibonacciNR.hpp"
using namespace std;

int main() {

unsigned long long n = 1;

  while (n < 115) {

    clock_t t1, t2;

    cout << "Finding " << n << "th fibonacci number....\n" << endl;

    if (n < 51) {

      ofstream ofs;
      ofs.open("recursive.txt", ios::app);

      cout << "Calling Recursive Fibonacci implementation" << endl;
      FibonacciR fibr(n);
      t1 = clock();
      fibr.PrintFibonacci();
      t1 = clock() - t1;
      cout << "Time to execute: " << t1 << " clicks (" << t1/CLOCKS_PER_SEC << " seconds)\n" << endl;

      ofs << t1 << "\n";
      ofs.close();

    }

    ofstream ofs;
    ofs.open("non_recursive.txt", ios::app);

    cout << "Calling Non-Recursive Fibonacci implementation" << endl;
    FibonacciNR fibnr(n);
    t2 = clock();
    fibnr.PrintFibonacci();
    t2 = clock() - t2;
    cout << "Time to execute: " << t2 << " clicks (" << t2/CLOCKS_PER_SEC << " seconds)\n" << endl;

    ofs << t2 << "\n";
    ofs.close();

    n += 1;

  }

  cout << "\nThat's all folks!\n" << endl;

  return 0;

}
