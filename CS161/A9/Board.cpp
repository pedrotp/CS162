/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/29/2016

** Description: Module 9, Assignment 9 -  Part of a two-player
tic-tac-toe game. This file is part of the Board class, which defines
a game board and the things that can be done within it. This is the
implementation file for the Board class, which defines all the functions
the class contains.

*********************************************************************/

#include "Board.hpp"
#include <string>
#include <iostream>

/*********************************************************************

** Description:

** This is the default constuctor that sets the every value on the board
array to empty and numMoves to 0

*********************************************************************/

Board::Board()
{
  numMoves = 0;
  for (int i = 0; i < 3; i++)
  {
    for (int j = 0; j < 3; j++)
    {
      moves[i][j] = '.';
    }
  }
}

/*********************************************************************

** Description: makeMove()

** This function places a move on the board. It takes coordinates and
an x or o char and places the corresponding char on that slot in the
board if the slot is available. If it is not available, then it returns
false.

*********************************************************************/

bool Board::makeMove(int xCoord, int yCoord, char playerChar)
{
  bool success = false; // variable to hold whether the move was successful

  if (moves[xCoord][yCoord] == '.') // if the space is empty, place the move
  {
    moves[xCoord][yCoord] = playerChar;
    success = true;
    numMoves++;
  }
  return success;
}

/*********************************************************************

** Description: gameState()

** This is the function that holds most of the game logic, as it is
used to check the status of the game. It uses a series of conditional
statements and loops to go through every scenario and return whether
the game is still going, or it has ended in a draw or a winner.

*********************************************************************/

State Board::gameState()
{
  State gameState = UNFINISHED;

  // this loop checks whether there is a winning combination in the rows and columns of the grid
  for (int i = 0; i < 3; i++)
  {
    if ((moves[i][0] == moves[i][1] && moves[i][1] == moves[i][2]) || (moves[0][i] == moves[1][i] && moves[1][i] == moves[2][i]))
    {
      if (moves[i][i] == 'x')
      {
        gameState = X_WON;
      }
      if (moves[i][i] == 'o')
      {
        gameState = O_WON;
      }
    }
  }

  // and this if statement checks the diagonals
  if ((moves[0][0] == moves[1][1] && moves[1][1] == moves[2][2]) || (moves[0][2] == moves[1][1] && moves[1][1] == moves[2][0]))
  {
    if (moves[1][1] == 'x')
    {
      gameState = X_WON;
    }
    if (moves[1][1] == 'o')
    {
      gameState = O_WON;
    }
  }

  // finally this checks to see if there are no more moves left (9 is the max)and calls a draw
  if (numMoves > 8 && gameState == UNFINISHED) {
    gameState = DRAW;
  }

  return gameState;
}

/*********************************************************************

** Description: print()

** In this function we use a for loop to print each line of the board
along with labels indicating x and y coordinates.

*********************************************************************/

void Board::print()
{
  std::cout << "  0 1 2" << std::endl;

  for (int i = 0; i < 3; i++)
  {
    std::cout << i << " " << moves[i][0] << " " << moves[i][1] << " " << moves[i][2] << std::endl;
  }
}
