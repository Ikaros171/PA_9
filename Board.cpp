#include "Board.h"

// overloaded assignment operator
Board& Board::operator= (Board& rhs)
{
	if (this != &rhs) // check for self-assignment
	{
		this->_sprite = rhs._sprite;
		this->_fileName = rhs._fileName;
		this->_texture = rhs._texture;
		this->_x = rhs._x;
		this->_y = rhs._y;
		for (int i = 0; i < 106; i++)
		{
			this->_cellArray[i] = rhs._cellArray[i];
		}
	}
	return *this;
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

//getter for cell at index pos
Cell& Board::getCell(int pos)
{
	return this->_cellArray[pos];
}