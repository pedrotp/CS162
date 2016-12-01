#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "FibonacciR.hpp"
#include "FibonacciNR.hpp"
using namespace std;

int main() {

int n = 10;

  while (n <= 100) {

    clock_t t1, t2;

    cout << "Finding " << n << "th fibonacci number....\n" << endl;

    // cout << "Calling Recursive Fibonacci implementation" << endl;
    // FibonacciR fibr(n);
    // t1 = clock();
    // fibr.PrintFibonacci();
    // t1 = clock() - t1;
    // cout << "Time to execute: " << t1 << " clicks (" << t1/CLOCKS_PER_SEC << " seconds)\n" << endl;

    cout << "Calling Non-Recursive Fibonacci implementation" << endl;
    FibonacciNR fibnr(n);
    t2 = clock();
    fibnr.PrintFibonacci();
    t2 = clock() - t2;
    cout << "Time to execute: " << t2 << " clicks (" << t2/CLOCKS_PER_SEC << " seconds)\n" << endl;

    n += 10;

  }

    cout << "\nThat's all folks!\n" << endl;

  return 0;

}
