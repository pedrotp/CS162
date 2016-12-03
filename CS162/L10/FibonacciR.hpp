/*********************************************************************

** Program Filename: FibonacciR.hpp

** Author: Pedro Torres-Picon

** Date: 12/05/2016

** Description: Lab 10 - This is the interface file for a FibonacciR
class, which executes a recursive function to calculate fibonacci
numbers. This file includes the class, variable and function declarations.

** Source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c

*********************************************************************/

#ifndef FIBONACCIR_HPP
#define FIBONACCIR_HPP

class FibonacciR {

private:
   FibonacciR();
   unsigned long long Fibonacci(const unsigned long long &n);
   const unsigned long long *n_;

public:
   FibonacciR(const unsigned long long &n);
   virtual ~FibonacciR();
   void PrintFibonacci();

};

#endif
