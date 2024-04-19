#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "GameObject.h"

class GamePiece : public GameObject
{
public:
	// constructor
	GamePiece(float x = 0.0, float y = 0.0, const string& fileName = "", const string& playerName = "") : GameObject(x, y, fileName)
	{
		this->_playerName = playerName;
	}
private:
	string _playerName;
};

