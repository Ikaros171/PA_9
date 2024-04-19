#pragma once

#include "GameObject.h"
#include "Button.h"

class Menu : public GameObject
{
public:
	// constructor
	Menu(float x = 0.0, float y = 0.0, const string& fileName = "") : GameObject(x, y, fileName)
	{
		
	}

	// deconstructor
	~Menu();

	// getters for the buttons, returns a reference so we may modify position
	Button& getBtn0();
	Button& getBtn1();
	Button& getBtn2();

	// overrides the draw function from GameObject base class because the menu will need to draw a background texture as well
	// as the three buttons
	void draw(sf::RenderWindow& window);

private:
	/*
	* Note: most of the menus we instantiate will not have 3 buttons (only the title screen), but to avoid creating a separate class
	* for each menu, we'll just make the buttons transparent and send them with Bilbo on an adventure to the Lonely Mountain
	* if they aren't needed.
	*/
	Button _btn0;
	Button _btn1;
	Button _btn2;
};

