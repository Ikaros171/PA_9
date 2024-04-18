#include "Transport.h"

// constructor
Transport::Transport(int startX, int startY, int endX, int endY)
{
	this->_startX = startX;
	this->_startY = startY;
	this->_endX = endX;
	this->_endY = endY;
}

// destructor
Transport::~Transport()
{
	// handled by the Call Stack
}