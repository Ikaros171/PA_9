#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "GameObject.h"

class GamePiece : public GameObject
{
public:
	// constructor
	GamePiece(float x, float y, const string& fileName, int xCord, int yCord) : GameObject(x, y, fileName)
	{
		this->_xCord = xCord;
		this->_yCord = yCord;
	}
private:
	int _xCord;
	int _yCord;
};

