#pragma once

#include "Board.h"
#include "GamePiece.h"

//All commented out until other functions are built
//UNCOMMENT LATER WHEN THEY ARE IMPLEMENTED

class GamePlay 
{
public:
	//constructor
	GamePlay();

	//functions
	bool playerTurn(int playerNumber, int bonus = 6);
	int roll();

private:
	Board _gameBoard;
	GamePiece _player1;
	GamePiece _player2;
};