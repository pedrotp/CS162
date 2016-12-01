
#ifndef FIBONACCIR_H_
#define FIBONACCIR_H_

class FibonacciR {

private:
   FibonacciR();
   int Fibonacci(const int &n);
   const int *n_;

public:
   FibonacciR(const int &n);
   virtual ~FibonacciR();
   void PrintFibonacci();

};

#endif
