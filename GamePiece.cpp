#include "GamePiece.h"

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