# Lab 07

This is a program that demonstrates a few sorting and search algorithms

## Installation

Run the terminal command `make` from the directory where all the files were unzipped

## Usage

To run the program, run the `./ss` command from the terminal. A menu will come up
asking which of the three algorithms to test:

1. Linear Search
2. Bubble Sort
3. Binary Search

After selecting an algorithm, select a file with numbers separated by spaces or newlines. The file will be read and turned into an array.

There are a few files provided, described below, but feel free to create new files of numbers for testing. The filename can be provided without a file path if the file is in the same directory as the executable file. If it is not, a file path must be specified.

* zero_begin.txt - has all the numbers from 0 to 9, with zero towards the beginning
* zero_middle.txt - has all the numbers from 0 to 9, with zero towards the middle
* zero_end.txt - has all the numbers from 0 to 9, with zero towards the endif
* no_zero.txt - has the numbers from 1 to 9, no zero
* sorted.txt - has a few random numbers, in ascending order
* not_sorted.txt - has a few random numbers, in no particular order
* empty.txt - the file is empty

To clean up the directory and remove all object files and executables, run the `make clean` command in the terminal
