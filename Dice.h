#pragma once

#include "Button.h"
#include "GameObject.h"

class Dice : public GameObject
{
public:
	// constructor
	Dice(float x = 100.0, float y = 800.0, const string& fileName = "Images/Default.png") : GameObject(x, y, fileName)
	{
		Button temp(sf::Vector2f(100, 100), sf::Vector2f(x, y));
		this->_rollDice = temp;
	}

	// overloaded assignment operator
	Dice& operator= (Dice& rhs);

	// copy assignment operator
	Dice(Dice& copy);

	// destructor
	~Dice();

	// getter
	Button& getRollDiceButton(); 

	// override the draw function from GameObject to also draw the button
	void draw(sf::RenderWindow& window);

private:
	Button _rollDice;
};

