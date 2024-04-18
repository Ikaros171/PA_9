#pragma once

#include "GameObject.h"

class cell : public GameObject, public sf::RectangleShape
{
public:
	bool ladder;
	bool snake;
	int x_destination;
	int y_destination;
};

class Board : public GameObject
{
public:
	// constructor
	Board(float x, float y, const string& fileName) : GameObject(x, y, fileName)
	{
		board = std::vector <std::vector<cell>>(10);
		for (int i = 0; i < 10; i++)
		{
			board.at(i) = std::vector<cell>(10);
		}
	}

	void player_moves(int x, int y, player& p);

private:
	std::vector <std::vector<cell>> board;
};

class player
{
public:

	std::string player;
	int x_cordinate;
	int y_cordinate;
};