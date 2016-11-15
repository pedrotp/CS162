/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/29/2016

** Description: Module 9, Assignment 9 -  Part of a two-player
tic-tac-toe game. This file is part of the Board class, which defines
a game board and the things that can be done within it. This is the
interface file for the Board class, which includes the class, variable
and function declarations.

*********************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

enum State {UNFINISHED, X_WON, O_WON, DRAW};

// Defines the interface of the Board class
class Board
{
  private:
    char moves[3][3];// 3 x 3 array to hold players' moves
    int numMoves; // a counter for how many moves there have been total

  public:
    Board(); // default constructor
    bool makeMove(int, int, char);
    State gameState();
    void print();
};
#endif
