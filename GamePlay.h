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

	void player_moves(int x, int y, GamePiece& p);

private:
	Board _gameBoard;
	GamePiece _players[2];
	sf::RenderWindow _gameWindow;
};