#include "Cell.h"

// constructor
Cell::Cell(float x, float y, int destIndex)
{
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