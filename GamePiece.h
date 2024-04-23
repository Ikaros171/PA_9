#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "GameObject.h"

class GamePiece : public GameObject
{
public:
	// constructor
	GamePiece(float x = 0.0, float y = 0.0, const string& fileName = "Images/Default.png", const string& playerName = "Player", 
		int pos = 0) : GameObject(x, y, fileName)
	{
		this->_playerName = playerName;
		this->_position = pos;
	}

	// overloaded assignment operator
	GamePiece& operator= (GamePiece& rhs);

	// copy constructor
	GamePiece(GamePiece& copy);

	// destructor
	~GamePiece();

	//getter 
	int getPos() const;

	//setter
	void setPos(int new_position);

private:
	string _playerName;
	int _position;
};

