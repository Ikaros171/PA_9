#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class Button : public sf::RectangleShape
{
public:
	Button(const sf::Vector2f& size, const sf::Vector2f& pos) : sf::RectangleShape(size)
	{
		this->setPosition(pos);
		this->setFillColor(sf::Color::Transparent);
	}

private:

};

