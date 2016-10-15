/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/15/2016

** Description: Lab 3 - Part of a simplified game of War, with dice.
This is the interface file for the Game class, which includes the
class, variable and function declarations.

*********************************************************************/

#ifndef GAME_HPP
#define GAME_HPP

#include "LoadedDie.hpp"

class Game {

  private:
    int numRounds;
    Die* p1Die;
    Die* p2Die;
    int p1Score;
    int p2Score;

  public:
    Game();
    void getUserInput();
    void play();
    void endGame();
    ~Game();
};

#endif
