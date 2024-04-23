#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Button : public sf::RectangleShape
{
public:
	// constructor
	Button(const sf::Vector2f& size = sf::Vector2f(100, 100), const sf::Vector2f& pos = sf::Vector2f(0, 0)) 
		: sf::RectangleShape(size)
	{
		this->setPosition(pos);
		this->setFillColor(sf::Color::Transparent);
	}

	// deconstructor
	~Button();

private:

};

