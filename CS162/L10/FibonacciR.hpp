
#ifndef FIBONACCIR_H_
#define FIBONACCIR_H_

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
