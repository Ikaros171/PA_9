#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

#include "GamePlay.h"
#include "TestFunctions.h"

int main(void)
{
	//debug mode changes whether it runs test functions or main game are run
	TestFunctions test;
	bool debug = test.debugOrGame();

	if (debug == false)
	{
		//create and play game
		GamePlay game;

		game.playGame();
	}
	else
	{
		//run all 5 test cases
		test.testCase1();
		test.testCase2();
		test.testCase3();
		test.testCase4();
		test.testCase5();
	}

	return 0;
}