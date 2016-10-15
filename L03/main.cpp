// #include <iostream>
// #include "Die.hpp"
// #include "LoadedDie.hpp"
#include "Game.hpp"

int main() {

  // Die lucky(6);
  // std::cout << "Not loaded die: " << std::endl;
  // int luckyAvg = 0;
  // for (int i = 0; i < 10; i++) {
  //   luckyAvg += lucky.roll();
  // }
  // luckyAvg /= 10;
  // std::cout << luckyAvg << std::endl;
  //
  // LoadedDie luckier(6);
  // std::cout << "Loaded die: " << std::endl;
  // int luckierAvg = 0;
  // for (int i = 0; i < 10; i++) {
  //   luckierAvg += luckier.roll();
  // }
  // luckierAvg /= 10;
  // std::cout << luckierAvg << std::endl;

  Game myGame;
  myGame.play();

  return 0;
}
