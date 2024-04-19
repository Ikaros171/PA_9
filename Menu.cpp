#include "Menu.h"

// deconstructor
Menu::~Menu()
{
	// handled by the call Stack
}

// getters for the buttons, returns a reference so we may modify position
Button& Menu::getBtn0()
{
	return this->_btn0;
}

Button& Menu::getBtn1()
{
	return this->_btn1;
}

Button& Menu::getBtn2()
{
	return this->_btn2;
}

// overrides the draw function from GameObject base class because the menu will need to draw a background texture as well
// as the three buttons
void Menu::draw(sf::RenderWindow& window)
{
	window.draw(this->_sprite);
	window.draw(this->_btn0);
	window.draw(this->_btn1);
	window.draw(this->_btn2);
}