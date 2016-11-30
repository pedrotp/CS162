


#ifndef FIBONACCINR_HPP
#define FIBONACCINR_HPP

  class FibonacciNR {
  public:
     FibonacciNR(const int &n);
     virtual ~FibonacciNR();
     void PrintFibonacci();
  private:
     FibonacciNR();
     int Fibonacci(const int &n);
     const int* n_;
  };
  
#endif
