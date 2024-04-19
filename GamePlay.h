#pragma once

#include "Board.h"
#include "GamePiece.h"
#include "Menu.h"

//All commented out until other functions are built
//UNCOMMENT LATER WHEN THEY ARE IMPLEMENTED

class GamePlay 
{
public:
	//constructor
	GamePlay();

	// wrapper for all the gameplay functions and drawing so main is nice and pristine
	void playGame();

	//functions
	bool playerTurn(int playerNumber, int bonus = 6);
	int roll();

private:
	Board _gameBoard;
	GamePiece _players[2];
	sf::RenderWindow _gameWindow;
};