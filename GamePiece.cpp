#include "GamePiece.h"

// overloaded assignment operator
GamePiece& GamePiece::operator= (GamePiece& rhs)
{
	if (this != &rhs) // check for self assignment
	{
		this->_fileName = rhs._fileName;
		this->_playerName = rhs._playerName;
		this->_position = rhs._position;
		this->_sprite = rhs._sprite;
		this->_texture = rhs._texture;
		this->_x = rhs._x;
		this->_y = rhs._y;
	}
	return (*this);
}

// copy constructor
GamePiece::GamePiece(GamePiece& copy)
{
	*this = copy;
}

// destructor
GamePiece::~GamePiece()
{
	// handled by the call stack
}

//getter
int GamePiece::getPos() const
{
	return _position;
}

//setter 
void GamePiece::setPos(int new_position)
{
	_position = new_position;
}