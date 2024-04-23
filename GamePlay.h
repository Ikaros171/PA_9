#pragma once

#include "Board.h"
#include "GamePiece.h"
#include "Menu.h"
#include "Dice.h"

#include <vector>
#include <Windows.h> // for the Sleep function; called within player turn so that user can see the changes in gamePiece position
					 // step by step instead of the program drawing it too fast

class GamePlay 
{
public:
	//constructor
	GamePlay();

	// wrapper for all the gameplay functions and drawing so main is nice and pristine
	void playGame();

	//functions
	bool playerTurn(int playerNumber, int bonus, std::vector<GameObject*>& drawVector, sf::Event event, bool& quit);
	int roll();

	// deals with loading the textures for the various menus and setting the position of the buttons - relegated it to a
	// function so it didn't take up too much space in playGame
	void setUpMenus(Menu& titleScreen, Menu& howToPlay, Menu& Player1Wins, Menu& Player2Wins);

private:
	Board _gameBoard;
	GamePiece _players[2];
	sf::RenderWindow _gameWindow;
	GameObject _bottomBanner;
	Dice _die;
};

//// deals with loading the textures for the various menus and setting the position of the buttons - relegated it to a non-member
//// function so it didn't take up too much space in playGame
//void setUpMenus(Menu& titleScreen, Menu& howToPlay, Menu& Player1Wins, Menu& Player2Wins);