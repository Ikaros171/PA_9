#include "GamePlay.h"
#include <time.h>

//constructor
GamePlay::GamePlay() 
{
	this->_gameWindow.create(sf::VideoMode(800, 900), "Chutes and Ladders"); // create game window
	//create board using default constructor
	Board temp(0, 0, "Images/Board.png");
	this->_gameBoard = temp;
	this->_gameBoard.load(this->_gameBoard.getFileName()); // load and set the board's texture to the sprite
	//create players using constructors with which image to use
	GamePiece player(0.0, 800.0, "Images/Player1.png", "Player 1", 0);
	GamePiece player2(0.0, 800.0, "Images/Player2.png", "Player 2", 0);
	this->_players[0] = player;
	this->_players[0].load(this->_players[0].getFileName()); // load and set the player's texture to the sprite
	this->_players[1] = player2;
	this->_players[1].load(this->_players[1].getFileName()); // load and set the player's texture to the sprite
	// this bottom banner is to hide the 800 x 100 black square beneath the game board and to display the dice when rolled
	GameObject temp2(0.0, 800.0, "Images/BottomBanner.png");
	this->_bottomBanner = temp2;
	this->_bottomBanner.load(this->_bottomBanner.getFileName());
}

// wrapper for all the gameplay functions and drawing so main is nice and pristine
void GamePlay::playGame()
{
	srand((unsigned int)time(nullptr)); // set seed for all dice rolls
	this->_gameWindow.setFramerateLimit(60);
	int index = 0, whoWon = -1, selection = -1;
	bool atTitle = true, atGame = false, atPlayer1Win = false, atPlayer2Win = false, quit = false;
	std::vector<GameObject*> drawVector; // used so we can just call the draw function for each element of the vector - we'll
										// add/remove elements as needed.
	Menu TitleScreen(0.0, 0.0, "Images/Title.png");
	Menu HowToPlay(0.0, 0.0, "Images/HowToPlay.png");
	Menu Player1Wins(0.0, 0.0, "Images/Player1Wins.png");
	Menu Player2Wins(0.0, 0.0, "Images/Player2Wins.png");
	setUpMenus(TitleScreen, HowToPlay, Player1Wins, Player2Wins); // setup the menus, textures, and sizes/positions of buttons
	drawVector.push_back(&TitleScreen); // default to showing the title screen when booting game

	while (this->_gameWindow.isOpen() && !quit)
	{
		sf::Event event;
		while (this->_gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				this->_gameWindow.close();
			}
			else if (event.type == sf::Event::MouseButtonReleased)
			{
				auto mousePosition = sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y);
				if (atTitle)
				{
					if (TitleScreen.getBtn0().getGlobalBounds().contains(mousePosition)) // clicked play game
					{
						selection = 1;
					}
					else if (TitleScreen.getBtn1().getGlobalBounds().contains(mousePosition)) // clicked how to play
					{
						selection = 2;
					}
					else if (TitleScreen.getBtn2().getGlobalBounds().contains(mousePosition)) // clicked exit game
					{
						selection = 3;
					}
				}
				else if (!atGame)
				{
					if (HowToPlay.getBtn0().getGlobalBounds().contains(mousePosition)) // go back to main menu
					{
						selection = 4;
					}
				}
			}
		}
		if (atGame)
		{
			if (whoWon != -1) // someone won
			{
				// logic for checking which player won in order to load the correct win screen
				drawVector.clear();
				atGame = false;
			}
			// game logic here

		}
		switch (selection)
		{
		case 1:
			whoWon = -1; // reinitialize in the event that user plays multiple times
			atTitle = false; // no longer at title
			atGame = true;
			drawVector.clear(); // get rid of the titlemenu for the draw loop
			drawVector.push_back(&(this->_gameBoard));
			drawVector.push_back(&(this->_bottomBanner));
			drawVector.push_back(&(this->_players[0]));
			drawVector.push_back(&(this->_players[1]));
			// push in the dice eventually
			break;
		case 2:
			drawVector.clear();
			drawVector.push_back(&HowToPlay);
			atTitle = false; // no longer at title
			break;
		case 3:
			quit = true;
			break;
		case 4:
			selection = 0; // reset so we don't immediately choose the same option without user input
			atPlayer1Win = false;
			atPlayer2Win = false;
			atTitle = true;
			drawVector.clear();
			drawVector.push_back(&TitleScreen);
			break;
		}


		// drawing loop
		this->_gameWindow.clear();
		for (index = 0; index < drawVector.size(); ++index)
		{
			(*(drawVector[index])).draw(this->_gameWindow);
		}
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
		if (temp.getDestIndex() != 0)
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



///////////////////////////////////////////////////////// Non-Member Functions //////////////////////////////////////////////
// 
// deals with loading the textures for the various menus and setting the position of the buttons - relegated it to a non-member
// function so it didn't take up too much space in playGame
void setUpMenus(Menu& titleScreen, Menu& howToPlay, Menu& Player1Wins, Menu& Player2Wins)
{
	titleScreen.load(titleScreen.getFileName()); // load the texture and attach it to the sprite
	titleScreen.getBtn0().setPosition(160, 180);
	titleScreen.getBtn0().setSize(sf::Vector2f(480, 90));
	titleScreen.getBtn1().setPosition(160, 360);
	titleScreen.getBtn1().setSize(sf::Vector2f(480, 90));
	titleScreen.getBtn2().setPosition(160, 540);
	titleScreen.getBtn2().setSize(sf::Vector2f(480, 90));

	howToPlay.load(howToPlay.getFileName()); // load the texture and attach it to the sprite
	howToPlay.getBtn0().setPosition(0, 0);
	howToPlay.getBtn0().setSize(sf::Vector2f(800, 900)); // want button to cover the whole screen
	howToPlay.getBtn1().setPosition(800, 900);
	howToPlay.getBtn1().setSize(sf::Vector2f(0, 0)); // sent with Bilbo
	howToPlay.getBtn2().setPosition(800, 900);
	howToPlay.getBtn2().setSize(sf::Vector2f(0, 0));

	Player1Wins.load(Player1Wins.getFileName()); // load the texture and attach it to the sprite
	Player1Wins.getBtn0().setPosition(0, 0);
	Player1Wins.getBtn0().setSize(sf::Vector2f(800, 900)); // want button to cover the whole screen
	Player1Wins.getBtn1().setPosition(800, 900);
	Player1Wins.getBtn1().setSize(sf::Vector2f(0, 0)); // sent with Bilbo
	Player1Wins.getBtn2().setPosition(800, 900);
	Player1Wins.getBtn2().setSize(sf::Vector2f(0, 0));

	Player2Wins.load(Player2Wins.getFileName()); // load the texture and attach it to the sprite
	Player2Wins.getBtn0().setPosition(0, 0);
	Player2Wins.getBtn0().setSize(sf::Vector2f(800, 900)); // want button to cover the whole screen
	Player2Wins.getBtn1().setPosition(800, 900);
	Player2Wins.getBtn1().setSize(sf::Vector2f(0, 0)); // sent with Bilbo
	Player2Wins.getBtn2().setPosition(800, 900);
	Player2Wins.getBtn2().setSize(sf::Vector2f(0, 0));
}