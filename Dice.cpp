#include "Dice.h"

// overloaded assignment operator
Dice& Dice::operator= (Dice& rhs)
{
	if (this != &rhs) // check for self-assignment
	{
		this->_fileName = rhs._fileName;
		this->_sprite = rhs._sprite;
		this->_x = rhs._x;
		this->_y = rhs._y;
		this->_texture = rhs._texture;
		this->_rollDice = rhs._rollDice;
	}
	return *this;
}

// copy assignment operator
Dice::Dice(Dice& copy)
{
	*this = copy;
}

// destructor
Dice::~Dice()
{
	// handled by the call stack
}

// getter
Button& Dice::getRollDiceButton()
{
	return this->_rollDice;
}

// override the draw function from GameObject to also draw the button
void Dice::draw(sf::RenderWindow& window)
{
	window.draw(this->_sprite);
	window.draw(this->_rollDice); // draw the button
}