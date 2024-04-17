#include "GameObject.h"

void GameObject::load(string& fileName)
{
	this->_texture.loadFromFile("fileName"); // load texture
	this->_sprite.setTexture(this->_texture); // set texture
	this->_sprite.setOrigin(sf::Vector2f(150, 150)); // set origin to center of 
}

void GameObject::draw(sf::RenderWindow& window)
{

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

