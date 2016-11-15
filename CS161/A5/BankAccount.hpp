/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/13/2016

** Description: Module 5, Assignment 5.b - Part of a program that
mimics the functionality of a bank account with customer data, deposits,
and withdrawals. This is the interface file that includes the class,
variable and function declarations.

*********************************************************************/

#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>

// Defines the interface of the BankAccount class
class BankAccount
{
  private:
    std::string customerName, customerID;
    double customerBalance;

  public:
    BankAccount();
    BankAccount(std::string, std::string, double);
    std::string getCustomerName();
    std::string getCustomerID();
    double getCustomerBalance();
    void withdraw(double);
    void deposit(double);
};
#endif
