#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class GamePiece : public sf::CircleShape
{
public:
	GamePiece(float radius, const sf::Vector2f& position, const sf::Color& colour) : sf::CircleShape(radius)
	{
		this->setFillColor(colour);
		this->setPosition(position);
	}
private:
};

