#include "GamePlay.h"

//constructor
GamePlay::GamePlay() 
{
	this->_gameWindow.create(sf::VideoMode(800, 900), "Chutes and Ladders"); // create game window
	//create board using default constructor
	Board temp(0, 0, "Images/Board.png");
	this->_gameBoard = temp;
	//create players using constructors with which image to use
	GamePiece player(0.0, 800.0, "Images/Player1.png", "Player 1");
	GamePiece player2(0.0, 800.0, "Images/Player2.png", "Player 2");
	this->_player1 = player;
	this->_player2 = player2;
}

//Function: playerTurn
// 
//Desctription: function is called after the roll input is recieved in main
//Cont: a dice is rolled for the player turn, updating the player position
//Cont: accordingly, checking if they are then at the start of a transport
//Cont: location, updating the position again if necessary, or if they are on
//Cont: the final tile and the game is over
// 
//Argument(s): 
//	int playerNumber : number to track which player should be moved
//	int bonus : if this number or greater is rolled, the player gets a second
//	int bonus : turn, default 6
//
//Returns: bool, true if end is reached, false if not

bool GamePlay::playerTurn(int playerNumber, int bonus) 
{
	//bools to track if the turn is finished, and if the player is at the end
	//of the game board yet
	bool fin = false, won = false;

	//main loop to play through the turn until a number < bonus is rolled
	while (fin == false) 
	{
		//roll

		//draw

		//check if transport

		//check if end is reached
	}
	return won;
}

void GamePlay::player_moves(int x, int y, GamePiece& p)
{
	/*board.at(x).at(y);

	if (board.at(x).at(y).getTransportStatus())
	{
		p.setPositionX(board.at(x).at(y).x_destination);
		p.setPositionY(board.at(x).at(y).y_destination);
	}*/
}

//Function: roll
//
//Description: generates a random number between 1-6, and draws the 
//Cont: corresponding dice image to the screen
//
//Argument(s):
//	int bonus: determines whether the bonus roll icon should be drawn
//
//Returns: int for dice roll
int GamePlay::roll()
{
	//generate number

	//draw

	//return result
}