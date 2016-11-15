/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/03/2016

** Description: Assignment 3.b - A program that prompts the user for a
filename, opens that file if possible, reads a set of integers in that
file, adds them together, and finally writes the sum to another file.

*********************************************************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
  ifstream inputFile;
  ofstream outputFile;
  string filename;
  double sum = 0, current;

  cout << "Please enter a file name." << endl;
  cin >> filename;

  inputFile.open(filename.c_str());

  if (inputFile) {
    while (inputFile >> current) {
      sum += current;
    }
    inputFile.close();

    outputFile.open("sum.txt");
    outputFile << sum << "\n";
    outputFile.close();
  } else {
    cout << "Error! Unable to open file with given file name." << endl;
  }

  return 0;
}
