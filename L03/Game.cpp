/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 10/15/2016

** Description: Lab 3 - Part of a simplified game of War, with dice.
This is the implementation file for the Game class, which includes
all the source code for the functions the class contains.

*********************************************************************/

#include <iostream>
#include "Game.hpp"
#include "helpers.hpp"

Game::Game() {
  p1Score = 0;
  p2Score = 0;
};

void Game::getUserInput() {
  int numSides;
  bool isLoaded;

  std::cout << "Welcome to War! (with dice)" << std::endl;
  std::cout << "The game is simple:" << std::endl;
  std::cout << "Enter the parameters for both dice, and the number of rounds to be played." << std::endl;
  std::cout << "Then, I will run the game and show you the results." << std::endl;

  std::cout << "First, enter the number of rounds we are going to play: " << std::endl;
  numRounds = getInt(1, 1000);

  std::cout << "Great! Enter the number of sides for Player 1's Die:" << std::endl;
  numSides = getInt(1, 1000);
  std::cout << "Is Player 1's Die loaded? (Y or N)" << std::endl;
  isLoaded = getYesNo();

  if (isLoaded) {
    p1Die = new LoadedDie(numSides);
    std::cout << "PLAYER 1: LOADED " << p1Die->getSides() << " SIDED DIE" << std::endl;
  } else {
    p1Die = new Die(numSides);
    std::cout << "PLAYER 1: UNLOADED " << p1Die->getSides() << " SIDED DIE" << std::endl;
  }

  std::cout << "OK. Now I need the number of sides for Player 2's Die:" << std::endl;
  numSides = getInt(1, 1000);
  std::cout << "Is Player 2's Die loaded? (Y or N)" << std::endl;
  isLoaded = getYesNo();

  if (isLoaded) {
    p2Die = new LoadedDie(numSides);
    std::cout << "PLAYER 2: LOADED " << p2Die->getSides() << " SIDED DIE" << std::endl;
  } else {
    p2Die = new Die(numSides);
    std::cout << "PLAYER 2: UNLOADED " << p2Die->getSides() << " SIDED DIE" << std::endl;
  }
};

void Game::play() {
  getUserInput();
  std::cout << "Press any key to begin the game..." << std::endl;
  std::cin.get();
  for (int i = 0; i < numRounds; i++) {
    int score1 = (p1Die->roll());
    int score2 = (p2Die->roll());
    std::cout << "P1: " << score1 << ", P2: " << score2 << " - ";
    if (score1 > score2) {
      p1Score++;
      std::cout << "P1 WINS";
    } else if (score2 > score1) {
      p2Score++;
      std::cout << "P2 WINS";
    } else {
      std::cout << "DRAW";
    }
    std::cout << std::endl;
  }
  endGame();
};

void Game::endGame() {
  std::cout << "**FINAL SCORES**" << std::endl;
  std::cout << "PLAYER 1: " << p1Score << " ROUNDS WON" << std::endl;
  std::cout << "PLAYER 2: " << p2Score << " ROUNDS WON" << std::endl;
  if (p1Score > p2Score) {
    std::cout << "** PLAYER 1 WINS THE GAME! **" << std::endl;
  } else if (p2Score > p1Score) {
    std::cout << "** PLAYER 2 WINS THE GAME! **" << std::endl;
  } else {
    std::cout << "** THE GAME IS A DRAW! **" << std::endl;
  }
};

Game::~Game() {
  delete p1Die;
  delete p2Die;
}
