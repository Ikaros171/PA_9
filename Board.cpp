#include "Board.h"

// constructor
Cell::Cell(bool transport, float x, float y, int destIndex)
{
	this->_transport = transport;
	this->_xCord = x;
	this->_yCord = y;
	this->_destIndex = destIndex;
}

// destructor
Cell::~Cell()
{
	// handled by the Call Stack
}

// getters
bool Cell::getTransportStatus() const
{
	return this->_transport;
}

float Cell::getXCord() const
{
	return this->_xCord;
}

float Cell::getYCord() const
{
	return this->_yCord;
}

int Cell::getDestIndex() const
{
	return this->_destIndex;
}

// setters
void Cell::setTransportStatus(bool status)
{
	this->_transport = status;
}

void Cell::setXCord(float newX)
{
	this->_xCord = newX;
}

void Cell::setYCord(float newY)
{
	this->_yCord = newY;
}

void Cell::setDestIndex(int newIndex)
{
	this->_destIndex = newIndex;
}

// overloaded assignment operator
Board& Board::operator= (Board& rhs)
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
Cell Board::getCell(int pos)
{
	return this->_cellArray[pos];
}