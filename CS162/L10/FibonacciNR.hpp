/*********************************************************************

** Program Filename: FibonacciNR.hpp

** Author: Pedro Torres-Picon

** Date: 12/05/2016

** Description: Lab 10 - This is the interface file for a FibonacciNR
class, which executes a non-recursive function which uses iteration
to calculate fibonacci numbers. This file includes the class,
variable and function declarations.

** Source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c

*********************************************************************/

#ifndef FIBONACCINR_HPP
#define FIBONACCINR_HPP

  class FibonacciNR {
  public:
     FibonacciNR(const unsigned long long &n);
     virtual ~FibonacciNR();
     void PrintFibonacci();
  private:
     FibonacciNR();
     unsigned long long Fibonacci(const unsigned long long &n);
     const unsigned long long* n_;
  };

#endif
