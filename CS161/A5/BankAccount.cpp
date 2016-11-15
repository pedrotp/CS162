/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/13/2016

** Description: Module 5, Assignment 5.b - Part of a program that
mimics the functionality of a bank account with customer data, deposits,
and withdrawals. This is the implementation file that defines all the
functions the class contains.

*********************************************************************/

#include <string>
#include "BankAccount.hpp"

std::string BankAccount::getCustomerName()
{
  return customerName;
}

std::string BankAccount::getCustomerID()
{
  return customerID;
}
double BankAccount::getCustomerBalance()
{
  return customerBalance;
}

/*********************************************************************

** Description:

** This function is used to withdraw an amount from the customer's
bank account. A provided double is deducted from the balance.

*********************************************************************/

void BankAccount::withdraw(double amount)
{
  customerBalance -= amount;
}

/*********************************************************************

** Description:

** This function is used to deposit an amount into the customer's
bank account. A provided double is added to the balance.

*********************************************************************/

void BankAccount::deposit(double amount)
{
  customerBalance += amount;
}

/*********************************************************************

** Description:

** This is the default constructor that sets all the variables to
default values

*********************************************************************/

BankAccount::BankAccount()
{
  customerName = "null";
  customerID = "null";
  customerBalance = 0;
}

/*********************************************************************

** Description:

** This constructor is used when values are provided and sets them to
the proper variables

*********************************************************************/

BankAccount::BankAccount(std::string name, std::string id, double balance)
{
  customerName = name;
  customerID = id;
  customerBalance = balance;
}
