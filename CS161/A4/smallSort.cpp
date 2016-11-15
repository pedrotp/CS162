/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/08/2016

** Description: Assignment 4.b - The smallSort function takes 3 integer
variables and reorganizes their values so that the lowest value is stored in
the first variable, the second lowest is in the second variable, and so on and
so forth.

*********************************************************************/

#include <iostream>
using namespace std;

// this is a helper function that just flips the values between two variables
void flip(int &num1, int &num2) {
  int temp = num2; // temporary variable to hold the value of num2
  num2 = num1;
  num1 = temp;
}

/*
In order to sort the three values, we create a flag variable called 'sorted'
that keeps track of whether all three variables are in the proper order. If
either of the two 'if' statements is executed, then it means the variables are
not properly sorted, so we flip those variables and re-execute the loop to check
again whether all are sorted properly this time.
*/

void smallSort(int &num1, int &num2, int &num3)
{
  bool sorted; // this variable tells us whether the variables are sorted properly
  do {
    sorted = true; // we set the variable to true by default
    if (num1 > num2) {
      flip(num1, num2);
      sorted = false; /* if we execute a flip then we set the variable to false
                      so the loop executes again */
    }
    if (num2 > num3) {
      flip(num2, num3);
      sorted = false;
    }
  } while (!sorted);
}

/*
int main() {
  int a, b, c;
  cout << "Please enter three integers." << endl;
  cin >> a;
  cin >> b;
  cin >> c;
  smallSort(a, b, c);
  cout << a << ", " << b << ", " << c << endl;
  return 0;
}
*/
