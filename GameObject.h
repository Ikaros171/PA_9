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
	GameObject(float x = 0, float y = 0, const string& fileName = "");

	// overloaded assignment operator
	GameObject& operator= (const GameObject& rhs);

	// copy constructor
	GameObject(const GameObject& copy);

	// destructor
	~GameObject();

	virtual void load(string& fileName);
	virtual void draw(sf::RenderWindow& window);

	// getters
	virtual float getPositionX() const;
	virtual float getPositionY() const;
	virtual string& getFileName();

	// setters
	virtual void setPositionX(float newX);
	virtual void setPositionY(float newY);

protected:
	sf::Sprite _sprite;
	float _x; // for position
	float _y; // for position
	sf::Texture _texture;
	string _fileName;
private:
};