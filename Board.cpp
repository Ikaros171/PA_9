#include "Board.h"

// overloaded assignment operator
Board& Board::operator= (Board& rhs)
{
	this->_sprite = rhs._sprite;
	this->_fileName = rhs._fileName;
	this->_texture = rhs._texture;
	this->_x = rhs._x;
	this->_y = rhs._y;
	this->board = rhs.board;
}

// copy constructor
Board::Board(Board& copy)
{
	*this = copy;
}

// deconstructor
Board::~Board()
{
	// handled by the Call Stack
}

void Board::player_moves(int x, int y, Player& p)
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