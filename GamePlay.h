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
	GameObject _bottomBanner;
};

// deals with loading the textures for the various menus and setting the position of the buttons - relegated it to a non-member
// function so it didn't take up too much space in playGame
void setUpMenus(Menu& titleScreen, Menu& howToPlay, Menu& Player1Wins, Menu& Player2Wins);