
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
