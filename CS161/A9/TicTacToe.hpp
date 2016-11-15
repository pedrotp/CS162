/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/29/2016

** Description: Module 9, Assignment 9 -  Part of a two-player
tic-tac-toe game. This file is part of the TicTacToe class, which
allows two people to play a game of tic-tac-toe using the previously
defined Board class. This is the interface file for the TicTacToe class,
which includes the class, variable and function declarations.

*********************************************************************/

#ifndef TICTACTOE_HPP
#define TICTACTOE_HPP

#include "Board.hpp"

// Defines the interface of the TicTacToe class
class TicTacToe
{
  private:
    Board gameBoard;
    char currentTurn; // keeps track of who's turn it is

  public:
    TicTacToe(); // default constructor
    TicTacToe(char); // constructor with a first player provided
    void play();
};
#endif
