#pragma once

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include <iostream>
#include <string>

using std::string;

class GameObject
{
public:
	// constructor
	GameObject(float x, float y, const string& fileName);

	// destructor
	~GameObject();

	virtual void load(string& fileName);
	virtual void draw(sf::RenderWindow& window);

	// getters
	virtual float getPositionX() const;
	virtual float getPositionY() const;

	// setters
	virtual void setPositionX(float newX);
	virtual void setPositionY(float newY);

protected:
	sf::Sprite _sprite;
private:
	float _x; // for position
	float _y; // for position
	sf::Texture _texture;
	string _fileName;
	bool _isLoaded;
};