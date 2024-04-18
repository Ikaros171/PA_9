#pragma once

#include "GameObject.h"

class cell : public GameObject, public sf::RectangleShape
{
public:

	bool ladder;
	int x_destination;
	int y_destination;
	bool snake;



};

class Board
{
public:
	std::vector <std::vector<cell>> board;

	Board()
	{
		board = std::vector <std::vector<cell>>(10);
		for (int i = 0; i < 10; i++)
		{
			board.at(i) = std::vector<cell>(10);
		}
	}

	void player_moves(int x, int y, player& p)
	{
		board.at(x).at(y);

		if (board.at(x).at(y).ladder)
		{
			p.x_cordinate = board.at(x).at(y).x_destination;
			p.y_cordinate = board.at(x).at(y).y_destination;
		}

		if (board.at(x).at(y).snake)
		{
			p.x_cordinate = board.at(x).at(y).x_destination;
			p.y_cordinate = board.at(x).at(y).y_destination;
		}

	}

};

class player
{
public:

	std::string player;
	int x_cordinate;
	int y_cordinate;


	
};