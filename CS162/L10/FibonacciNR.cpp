/*********************************************************************

** Program Filename: FibonacciNR.cpp

** Author: Pedro Torres-Picon

** Date: 12/05/2016

** Description: Lab 10 - This is the implementation file for a FibonacciNR
class, which executes a non-recursive function which uses iteration
to calculate fibonacci numbers. This file the source code for all the
functions in the class.

** Source: https://www.codeproject.com/tips/109443/fibonacci-recursive-and-non-recursive-c

*********************************************************************/

#include "FibonacciNR.hpp"
#include <iostream>

FibonacciNR::FibonacciNR() {

}

FibonacciNR::FibonacciNR(const unsigned long long &n):n_(&n){

}

FibonacciNR::~FibonacciNR() {

}

unsigned long long FibonacciNR::Fibonacci(const unsigned long long &n) {
   unsigned long long first =0;
   unsigned long long second=1;
   unsigned long long counter=2;
   while(counter < n)
   {
       unsigned long long temp=second;
       second=first+second;
       first=temp;
       ++counter;
   }
   if(n==0)
       return 0;
   else
       return first+second;
}

void FibonacciNR::PrintFibonacci() {
   const unsigned long long result = Fibonacci(*n_);
  std::cout << *n_ << "th fibonaci number: " << result << std::endl;
}
