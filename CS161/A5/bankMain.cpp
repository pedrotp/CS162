#include "BankAccount.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{

  BankAccount account1("Harry Potter", "K4637", 8032.78);
  account1.withdraw(244.0);
  account1.withdraw(3012.58);
  account1.deposit(37.54);
  account1.withdraw(1807.12);
  account1.deposit(500.00);
  double finalBalance = account1.getCustomerBalance();

  cout << "Final balance for " << account1.getCustomerName() << " (" << account1.getCustomerID() << ") is " << finalBalance << endl;

  return 0;
}
