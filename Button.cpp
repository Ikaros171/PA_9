#include "Button.h"

// deconstructor
Button::~Button()
{
	// handled by the Call Stack
}

bool Button::wasClicked(sf::Event& event) const
{
	// get mouse position from the event
	auto mousePosition = sf::Vector2f((float)event.mouseButton.x, (float)event.mouseButton.y);

	if (this->getGlobalBounds().contains(mousePosition))
	{
		return true;
	}
	else
	{
		return false;
	}
}