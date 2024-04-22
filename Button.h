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
		this->setFillColor(sf::Color::Transparent); // change to transparent later
	}

	// deconstructor
	~Button();

	// returns true if the button was clicked, false otherwise. To be called within the gameplay loop to determine which menu
	// and/or gameboard to draw
	bool wasClicked(sf::Event& event) const;

private:

};

