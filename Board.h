#pragma once

#include "GameObject.h"

#include <vector>

using std::vector;

class Board : public GameObject
{
public:
	// constructor
	Board(float x, float y, const string& fileName) : GameObject(x, y, fileName)
	{

	}
private:
	
};

