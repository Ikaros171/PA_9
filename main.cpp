#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

int main(void)
{
	sf::RenderWindow gameWindow;
	gameWindow.create(sf::VideoMode(1000, 1000), "Chutes and Ladders");

	while (gameWindow.isOpen())
	{
		sf::Event event;
		while (gameWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				gameWindow.close();
			}
		}
	}

	return 0;
}