/*********************************************************************

** Author: Pedro Torres-Picon

** Date: 07/29/2016

** Description: Module 9, Assignment 9 -  Part of a two-player
tic-tac-toe game. This file is part of the TicTacToe class, which
allows two people to play a game of tic-tac-toe using the previously
defined Board class. This is the implementation file for the TicTacToe
class, which defines all the functions the class contains.

*********************************************************************/

#include <iostream>
#include <string>
#include "TicTacToe.hpp"

/*********************************************************************

** Description:

** This is the default constuctor that gives the first turn to O if
no first player is specified.

*********************************************************************/

TicTacToe::TicTacToe()
{
  currentTurn = 'o';
}

/*********************************************************************

** Description:

** This is a constuctor that gives the first turn to whichever symbol,
X or O, the user specifies.

*********************************************************************/

TicTacToe::TicTacToe(char firstTurn)
{
  currentTurn = firstTurn;
}

/*********************************************************************

** Description: play()

** This is the function that starts the game. We take input from the
user to see who goes first, and then we loop through a sequence that
asks each player to make a move until there is a winner or the game
ends in a draw. We also print the game board often so the players
can visiualize the positions of the pieces.

*********************************************************************/

void TicTacToe::play()
{
  int xCoord, yCoord;

  // this loop keeps iterating while the game state is unfinished
  while (gameBoard.gameState() == UNFINISHED)
  {
    gameBoard.print(); // print the board first to show users where things stand
    std::cout << std::endl; // blank line for readability
    std::cout << "Player " << currentTurn << ": please enter your move." << std::endl;
    std::cin >> xCoord >> yCoord; // take two coordinates for the move
    if (!gameBoard.makeMove(xCoord,yCoord,currentTurn)) // make the move, and if it returns false then tell the user the square is taken
    {
        std::cout << std::endl << "**That square is already taken.**" << std::endl;
    } else { // otherwise, switch to other player
      if (currentTurn == 'x')
      {
        currentTurn = 'o';
      } else if (currentTurn == 'o')
      {
        currentTurn = 'x';
      }
    }
  }

  // this switch statement is reached when the game is over, and it regulates
  // which message is displayed to the user depending on the final game state
  switch (gameBoard.gameState())
  {
    case X_WON: std::cout << std::endl << "** x wins! **"<< std::endl;
    break;

    case O_WON: std::cout << std::endl << "** o wins! **"<< std::endl;
    break;

    case UNFINISHED: // this is included purely to satisfy the c++ compiler warning, but will probably never get used
    case DRAW: std::cout << std::endl << "** it's a draw! **"<< std::endl;
    break;
  }
  gameBoard.print(); // print the board one final time to show the final state of the game
}

/*********************************************************************

** Description:

** This is the main method which actually runs the game when the program
is executed. It asks which player goes first, creates a new TicTacToe
object and starts the game. 

*********************************************************************/

int main() {
  char firstPlayer;

  std::cout << "Welcome to Tic Tac Toe!" << std::endl;
  std::cout << "Who goest first? Please enter x or o." << std::endl;
  std::cin >> firstPlayer;

  TicTacToe newGame(firstPlayer);
  newGame.play();

  return 0;
}
