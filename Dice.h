#pragma once

#include "GameObject.h"

class DiceRoll : public GameObject
{
public:
    DiceRoll() : window(sf::VideoMode(200, 200), "Dice Roll") {
        std::srand(std::time(nullptr)); // Seed the random number generator
        int randomNumber = std::rand() % 6 + 1; // Generate a random number between 1 and 6

        if (!texture.loadFromFile("dice_" + std::to_string(randomNumber) + ".png")) {
            std::cerr << "Failed to load dice image" << std::endl;
        }
        sprite.setTexture(texture);
    }

private:
    
};