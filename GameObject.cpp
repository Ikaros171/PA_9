#include "GameObject.h"

// constructor
GameObject::GameObject(float x, float y, const string& fileName)
{
	this->_x = x;
	this->_y = y;
	this->_fileName = fileName;
}

// destructor
GameObject::~GameObject()
{
	// handled by the Call Stack
}

void GameObject::load(string& fileName)
{
	this->_texture.loadFromFile(fileName); // load texture
	this->_sprite.setTexture(this->_texture); // set texture
}

void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(this->_sprite);
}

// getters
float GameObject::getPositionX() const
{
	return this->_x;
}

float GameObject::getPositionY() const
{
	return this->_y;
}

// setters
void GameObject::setPositionX(float newX)
{
	this->_x = newX;
}

void GameObject::setPositionY(float newY)
{
	this->_y = newY;
}