/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/20/2016

** Description: Module 7, Assignment 7 - Test file

*********************************************************************/

#include <iostream>

using namespace std;

int main()
{
  const int NUM = 7;
  int array[] = {1,0,2,2,8,9,9};
  vector<int> mode = findMode(array, NUM);

  cout << "array: ";

  for (int i = 0; i < NUM; i++) {
    cout << array[i] << " ";
  }

  cout << endl << "mode(s): ";

  for (int i = 0; i < mode.size(); i++) {
    cout << mode.at(i) << " ";
  }

  return 0;
}
