


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
