#include "GamePlay.h"
#include <time.h>

//constructor
GamePlay::GamePlay() 
{
	this->_gameWindow.create(sf::VideoMode(800, 900), "Chutes and Ladders"); // create game window
	//create board using default constructor
	Board temp(0, 0, "Images/Board.png");
	this->_gameBoard = temp;
	//create players using constructors with which image to use
	GamePiece player(0.0, 800.0, "Images/Player1.png", "Player 1", 0);
	GamePiece player2(0.0, 800.0, "Images/Player2.png", "Player 2", 0);
	this->_players[0] = player;
	this->_players[1] = player2;
}

// wrapper for all the gameplay functions and drawing so main is nice and pristine
void GamePlay::playGame()
{
	srand((unsigned int)time(nullptr)); // set seed for all dice rolls
	int index = 0;
	std::vector<GameObject> drawVector; // used so we can just call the draw function for each element of the vector - we'll
										// add/remove elements as needed.
	

	while (this->_gameWindow.isOpen())
	{
		sf::Event event;
		while (this->_gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_gameWindow.close();
			}
		}




		this->_gameWindow.clear();

		this->_gameWindow.display();
	}
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
	int die_roll = 0;

	//main loop to play through the turn until a number < bonus is rolled
	while (fin == false) 
	{
		//roll
		die_roll = roll();

		//draw
			//draw dice roll

			//Update player position
			//get cell for destination of roll
			Cell new_cell = this->_gameBoard.getCell(_players[playerNumber].getPos() + die_roll);

			//set X/Y coords
			_players[playerNumber].setPositionX(new_cell.getXCord());
			_players[playerNumber].setPositionY(new_cell.getYCord());

			//draw new player position


		//check if transport
		Cell temp = this->_gameBoard.getCell(_players[playerNumber].getPos());
		if (temp.getTransportStatus() == true)
		{
			//is a transport spot update player position
			//temp int for new position
			int dest = temp.getDestIndex();

			//cell for destination
			Cell dest_cell = this->_gameBoard.getCell(dest);

			//update position
			_players[playerNumber].setPos(dest);

			//update X/Y coordinates
			_players[playerNumber].setPositionX(dest_cell.getXCord());
			_players[playerNumber].setPositionY(dest_cell.getYCord());

			//draw at new position
		}

		//check if bonus roll
		if (die_roll > (bonus - 1))
		{
			//player gets another roll

			//before running next turn check if end is reached
			if (_players[playerNumber].getPos() > 99)
			{
				won = true;
				return won;
			}
			else
			{
				//run bonus turn
				playerTurn(playerNumber, bonus);
			}
		}

		//check if end is reached
		if (_players[playerNumber].getPos() > 99)
		{
			won = true;
		}
	}
	return won;
}

//Function: roll
//
//Description: generates a random number between 1-6
//
//Argument(s):
//	int bonus: determines whether the bonus roll icon should be drawn
//
//Returns: int for dice roll
int GamePlay::roll()
{
	//generate and return a number 1 - 6
	return ((rand() % 6) + 1);
}