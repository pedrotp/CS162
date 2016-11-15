#include <iostream>

int main () {

  srand (std::time(NULL));
  int test = 0;

  for (int i = 0; i < 1000; i++) {
    test += rand() % 100 + 1;
  }

  std::cout << test / 1000 << std::endl;

  return 0;

}
