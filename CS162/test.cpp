#include <iostream>
#include <curses.h>

int main () {

  int ch;
  do {
    // std::cin.clear();
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    std::cout << "CHAR: " << ch << std::endl;
    ch = getch();
  } while (ch != KEY_RIGHT);

  return 0;

}
